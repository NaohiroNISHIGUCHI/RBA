/**
 * Copyright (c) 2019 DENSO CORPORATION.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/// @file  RBAIsTypeOfOperatorMaker.cpp
/// @brief IsTypeOf object generation class definition file

#include "RBAIsTypeOfOperatorMaker.hpp"
#include "RBAJsonElement.hpp"
#include "RBAModelElement.hpp"
#include "RBAModelImpl.hpp"
#include "RBAModelFactory.hpp"
#include "RBAIsTypeOfOperator.hpp"

namespace rba
{

RBAIsTypeOfOperatorMaker::RBAIsTypeOfOperatorMaker()
  : RBAOperatorMaker{"IsTypeOf"}
{
}

std::unique_ptr<RBAModelElement>
RBAIsTypeOfOperatorMaker::createInstance(const std::string& name)
{
  return std::make_unique<RBAIsTypeOfOperator>();
}

RBAModelElement*
RBAIsTypeOfOperatorMaker::setProperty(RBAModelElement* element,
                                      const RBAJsonElement* jsonElem,
                                      RBAModelImpl* model,
                                      RBAModelElement* owner)
{
  RBAIsTypeOfOperator* const isTypeOfOpe
    {dynamic_cast<RBAIsTypeOfOperator*>(element)};

  // Set LetStatement
  const std::int32_t pop_num {setLetStatement(model, isTypeOfOpe, jsonElem)};

  // Set operand
  const RBAJsonElement* const operand {jsonElem->findChildren("operand")};
  const RBAJsonElement* const param {operand->getChild()};
  RBAModelElement* const expr {getFactory()->createElement(param->getClassName(), param)};
  isTypeOfOpe->addOperand(dynamic_cast<RBAExpression*>(expr));
  // Set Tag
  const RBAJsonElement* const tagElem {jsonElem->findChildren("tagName")};
  isTypeOfOpe->setTag(tagElem->getString());

  // Pop variable
  for(std::int32_t i{0}; i<pop_num; i++) {
    getFactory()->popVariable();
  }

  return isTypeOfOpe;
}

}
