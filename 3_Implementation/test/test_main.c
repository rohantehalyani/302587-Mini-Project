#include <unity.h>
#include <unity_internals.h>
#include "header.h"

#define PROJECT_NAME "NumberConversion"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_convert(void)
{
	TEST_ASSERT_EQUAL(5,convert(101));
	TEST_ASSERT_EQUAL(37,convert(100101));	
}

void test_hexadecial(void)
{
	TEST_ASSERT_EQUAL(122,HexadecimalToDecimal("5a"));
	TEST_ASSERT_EQUAL(79,HexadecimalToDecimal("2f"));
}


int main(){
    UNITY_BEGIN();


    RUN_TEST(test_convert);
    RUN_TEST(test_hexadecial);

    return UNITY_END();
}
