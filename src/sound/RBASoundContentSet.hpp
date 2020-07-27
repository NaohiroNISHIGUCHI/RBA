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
 * SoundContentSet class header
 */

#ifndef RBASOUNDCONTENTSET_HPP
#define RBASOUNDCONTENTSET_HPP

#include "RBAContentSet.hpp"
#include "RBADllExport.hpp"

namespace rba
{

class RBASoundContent;
class RBASoundContentImpl;

class DLL_EXPORT RBASoundContentSet : public RBAContentSet
{
public:
  explicit RBASoundContentSet(const std::string& name="");
  RBASoundContentSet(const RBASoundContentSet&)=delete;
  RBASoundContentSet(const RBASoundContentSet&&)=delete;
  RBASoundContentSet& operator=(const RBASoundContentSet&)=delete;
  RBASoundContentSet& operator=(const RBASoundContentSet&&)=delete;
  virtual ~RBASoundContentSet()=default;

public:
  const std::list<const RBASoundContent*>& getTargets() const;
  void addTarget(const RBAContent* content) override;
  void clear() override;
  RBAModelElementType getModelElementType() const override;

private:
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4251)
#endif
  std::list<const RBASoundContent*> externalContents_;
#ifdef _MSC_VER
#pragma warning(pop)
#endif

};

}

#endif
