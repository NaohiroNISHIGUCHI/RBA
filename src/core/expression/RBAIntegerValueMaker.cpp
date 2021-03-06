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

/// @file  RBAIntegerValueMaker.cpp
/// @brief IntegerValue object generation class definition file

#include "RBAIntegerValueMaker.hpp"
#include "RBAIntegerValue.hpp"
#include "RBAJsonElement.hpp"
#include "RBAModelElement.hpp"
#include "RBAModelImpl.hpp"
#include "RBAModelFactory.hpp"

namespace rba
{

RBAIntegerValueMaker::RBAIntegerValueMaker()
  : RBAExpressionMaker{"IntegerValue"}
{
}

std::unique_ptr<RBAModelElement>
RBAIntegerValueMaker::createInstance(const std::string& name)
{
  return std::make_unique<RBAIntegerValue>();
}

RBAModelElement*
RBAIntegerValueMaker::setProperty(RBAModelElement* element,
                                  const RBAJsonElement* jsonElem,
                                  RBAModelImpl* model,
                                  RBAModelElement* owner)
{
  RBAIntegerValue* const intVal {dynamic_cast<RBAIntegerValue*>(element)};

  // Set LetStatement
  const std::int32_t pop_num {setLetStatement(model, intVal, jsonElem)};

  // Set value
  const RBAJsonElement* const valueElem {jsonElem->findChildren("value")};
  intVal->setValue(stoi(valueElem->getString()));

  // Pop variable
  for(std::int32_t i{0}; i<pop_num; i++) {
    getFactory()->popVariable();
  }

  return intVal;
}

}
