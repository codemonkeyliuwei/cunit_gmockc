/*
 * UT Test file
 */
#include "math.h"               //the header file to be test
#include "math_mock.h"
#include "CUnit/Console.h"      //Console mode
#include "CUnit/Automated.h"    //Automated mode
#include <cmock/cmock.h>

using namespace ::testing;

int InitSuite()
{
    printf("Math test init!\n");
    return 0;
}

int EndSuite()
{
    printf("Math test end\n");
    return 0;
}

//test case
void TestCaseSumWithGmockc()
{
    int ret = 0;
    
    sumFunctionMock mock;

    {
	// mock one time
    	EXPECT_FUNCTION_CALL(mock, (5, 10)).WillOnce(Return(16));
    	ret = sum(5, 10);
    	CU_ASSERT_EQUAL(ret, 16);
    }

    {
	// mockk multipul times 
    	EXPECT_FUNCTION_CALL(mock, (_, _))
		.WillOnce(Return(16))
		.WillOnce(Return(3))
	        .WillRepeatedly(Return(20));
    	ret = sum(5, 10);
    	CU_ASSERT_EQUAL(ret, 16);
    	ret = sum(5, 10);
    	CU_ASSERT_EQUAL(ret, 3);
    	ret = sum(5, 10);
    	CU_ASSERT_EQUAL(ret, 20);
    	ret = sum(1, -1);
    	CU_ASSERT_EQUAL(ret, 20);
    }
}

// gets rid of annoying "deprecated conversion from string constant" warning
#pragma GCC diagnostic ignored "-Wwrite-strings"
int AddMathTest(void)
{
    CU_TestInfo testcases[] = {
        {"TestCaseSumIsEqual:", TestCaseSumWithGmockc},
        CU_TEST_INFO_NULL
    };

    CU_SuiteInfo suites[] = {
        {"Testing for math:", InitSuite, EndSuite, testcases},
        CU_SUITE_INFO_NULL
    };

    // register suite
    if(CUE_SUCCESS != CU_register_suites(suites))
    {
        printf("CU_register_suites fail!\n");
        return -1;
    }

    return 0;
}
#pragma GCC diagnostic pop
