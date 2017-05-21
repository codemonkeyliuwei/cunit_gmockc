/*
 * The mock declare.
 */
#ifndef CMOCK_CUNIT_MATH_MOCK_H_
#define CMOCK_CUNIT_MATH_MOCK_H_

#include "math.h"
#include "cmock/cmock.h"

DECLARE_FUNCTION_MOCK2(sumFunctionMock, sum, int(int, int));

IMPLEMENT_FUNCTION_MOCK2(sumFunctionMock, sum, int(int, int));

#endif /* CMOCK_CUNIT_MATH_MOCK_H_ */

