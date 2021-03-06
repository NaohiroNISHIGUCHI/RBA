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

/// @file  RBAIsEqualToOperatorMaker.hpp
/// @brief IsEqualToOperator object generation file

#ifndef RBAISEQUALTOOPERATORMAKER_HPP
#define RBAISEQUALTOOPERATORMAKER_HPP

#include "RBAOperatorMaker.hpp"

namespace rba
{

/// @brief IsEqualToOperator object generation class
class RBAIsEqualToOperatorMaker : public RBAOperatorMaker
{
public:
  RBAIsEqualToOperatorMaker();
  RBAIsEqualToOperatorMaker(const RBAIsEqualToOperatorMaker&)=delete;
  RBAIsEqualToOperatorMaker(const RBAIsEqualToOperatorMaker&&)=delete;
  RBAIsEqualToOperatorMaker& operator=(const RBAIsEqualToOperatorMaker&)=delete;
  RBAIsEqualToOperatorMaker& operator=(const RBAIsEqualToOperatorMaker&&)=delete;
  virtual ~RBAIsEqualToOperatorMaker()=default;

protected:
  /// @brief generate an empty instance
  /// @details generate an empty instance of unique_ptr in derived class
  /// @return unique_ptr for instance
  std::unique_ptr<RBAModelElement> createInstance(const std::string& name="") override;

};

}

#endif
