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
 * PreviousModifier class header
 */


#ifndef RBAPREVIOUSMODIFIER_HPP
#define RBAPREVIOUSMODIFIER_HPP

#include <memory>
#include "RBAExpression.hpp"

namespace rba
{

class RBAPreviousObjectWrapper;

class DLL_EXPORT RBAPreviousModifier : public RBAExpression
{
public:
  RBAPreviousModifier();
  RBAPreviousModifier(const RBAPreviousModifier&)=delete;
  RBAPreviousModifier(const RBAPreviousModifier&&)=delete;
  RBAPreviousModifier& operator=(const RBAPreviousModifier&)=delete;
  RBAPreviousModifier& operator=(const RBAPreviousModifier&&)=delete;
  virtual ~RBAPreviousModifier()=default;

  void accept(RBAExpressionVisitor& visitor) override;
  void setObjReference(RBAExpression* const newObjRef);
  RBAExpression* const getObjReference() const;
  const RBARuleObject* getReferenceObjectCore(RBAConstraintInfo* info,
                                              RBAArbitrator* arb) const override;

  // Log
#ifdef RBA_USE_LOG
  virtual const std::string getSymbol() const;
  void createHierarchy() override;
  const std::string getExpressionText() const override;
  const std::string getCoverageExpressionText() const override;
  RBAExpressionType getUnderlyingType() const override;
#endif

private:
  // This pointer is not "const" in order to call 
  //  objReference_->getReferenceObject()
  RBAExpression* objReference_;
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4251)
#endif
  std::unique_ptr<RBAPreviousObjectWrapper> previousObj_;
#ifdef _MSC_VER
#pragma warning(pop)
#endif

};

}

#endif
