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

/// @file  RBAAllInstanceOfViewContentMaker.cpp
/// @brief AllInstanceOfViewContenta object generation class definition file
///
/// Copyright (c) 2019 DENSO CORPORATION. All rights reserved.

#include <iostream>
#include "RBAAllInstanceOfViewContentMaker.hpp"
#include "RBAJsonElement.hpp"
#include "RBAModelElement.hpp"
#include "RBAModelImpl.hpp"
#include "RBAAllInstanceOfViewContent.hpp"
#include "RBAModelFactory.hpp"

namespace rba
{

RBAAllInstanceOfViewContentMaker::RBAAllInstanceOfViewContentMaker()
  : RBAExpressionMaker{"AllInstanceOfViewContent"}
{
}

std::unique_ptr<RBAModelElement>
RBAAllInstanceOfViewContentMaker::createInstance(const std::string& name)
{
  return std::make_unique<RBAAllInstanceOfViewContent>();
}

RBAModelElement*
RBAAllInstanceOfViewContentMaker::setProperty(RBAModelElement* element,
                                              const RBAJsonElement* jsonElem,
                                              RBAModelImpl* model,
                                              RBAModelElement* owner)
{
  RBAAllInstanceOfViewContent* const allCont
    {dynamic_cast<RBAAllInstanceOfViewContent*>(element)};
  allCont->setContents(model->getViewContentImpls());

  return allCont;
}

}
