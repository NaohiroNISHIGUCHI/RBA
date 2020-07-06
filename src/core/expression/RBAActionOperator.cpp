/**
 * Action operator class　definition
 */

#include "RBAActionOperator.hpp"
#include "RBAExpressionType.hpp"

namespace rba
{

#ifdef RBA_USE_LOG
RBAExpressionType
RBAActionOperator::getUnderlyingType() const
{
  return RBAExpressionType::ACTION;
}
#endif

}
