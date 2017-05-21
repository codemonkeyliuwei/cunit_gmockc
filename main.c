/*
 * main for ut test
 */

#include <assert.h>
#include "gmock/gmock.h"
#include "CUnit/Console.h"      //Console mode
#include "CUnit/Automated.h"    //Automated mode

using namespace ::testing;

extern int AddMathTest(void);

int main(int argc, char* argv[])
{
    ::testing::GTEST_FLAG(throw_on_failure) = true;
    ::testing::InitGoogleMock(&argc, argv);

    //初始化测试单元
    if( CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    //获取测试单元, 确定初始化成功
    assert(NULL != CU_get_registry());

    //检测是否在执行
    assert(!CU_is_test_running());

    //添加测试用例  
    if (0 != AddMathTest())
    {
        CU_cleanup_registry();
        return CU_get_error(); 
    }

    //automated模式执行用例
    CU_set_output_filename("MathTest");
    CU_list_tests_to_file(); 
    CU_automated_run_tests();

    CU_cleanup_registry();

    return 0;
}

