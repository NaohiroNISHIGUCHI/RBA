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

/// @file  RBAAbstractMakerTable.cpp
/// @brief Maker table abstraction class definition

#include "RBAAbstractMakerTable.hpp"

namespace rba
{

const std::list<std::string>&
RBAAbstractMakerTable::getTags() const
{
  return tags_;
}

void
RBAAbstractMakerTable::addTag(const std::string& tag)
{
  tags_.push_back(tag);
}

}

