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
/// @file  RBAIsVisibleMaker.cpp
/// @brief IsVisible objct generation class

#include <iostream>
#include "RBAIsVisibleMaker.hpp"
#include "RBAJsonElement.hpp"
#include "RBAModelElement.hpp"
#include "RBAModelImpl.hpp"
#include "RBAModelFactory.hpp"
#include "RBAIsVisible.hpp"

namespace rba
{

RBAIsVisibleMaker::RBAIsVisibleMaker()
  : RBAOperatorMaker{"IsVisible"}
{
}

std::unique_ptr<RBAModelElement>
RBAIsVisibleMaker::createInstance(const std::string& name)
{
  return std::make_unique<RBAIsVisible>();
}

}
