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

/**
 * Constraint Implementation class header
 */

#ifndef RBACONSTRAINTIMPL_HPP
#define RBACONSTRAINTIMPL_HPP

#include "RBAConstraint.hpp"
#include "RBAAbstractConstraint.hpp"

namespace rba
{

class RBAArbitrator;

class DLL_EXPORT RBAConstraintImpl : public RBAConstraint,
                                     public RBAAbstractConstraint
{
public:
  explicit RBAConstraintImpl(const std::string& name="");
  RBAConstraintImpl(const RBAConstraintImpl&)=delete;
  RBAConstraintImpl(const RBAConstraintImpl&&)=delete;
  RBAConstraintImpl& operator=(const RBAConstraintImpl&)=delete;
  RBAConstraintImpl& operator=(const RBAConstraintImpl&&)=delete;
  virtual ~RBAConstraintImpl()=default;

public:
  void setRuntime(const bool newRuntime);
  std::string getName() const override;
  bool isConstraint() const override;
  bool isRuntime() const;
  bool execute(RBAArbitrator* const arb);

private:
  bool runtime_ {RUNTIME_EDEFAULT};
};

}

#endif
