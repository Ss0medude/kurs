#include <UnitTest++/UnitTest++.h>
#include "calculation.h"
#include <iostream>
#include <string>

using namespace std;


SUITE(calculation_Test)
{
    TEST(Positive) {
        std::vector<int16_t> vecto = {1,2,3,4,5};
        CHECK_EQUAL(120,*( calc().calculation(vecto)));
    }
    TEST(One_vector) {
        std::vector<int16_t> vecto = {2};
        CHECK_EQUAL(2,*( calc().calculation(vecto)));
    }
    TEST(Negative) {
        std::vector<int16_t> vecto = {-1, -2,-3,-4, -5};
        CHECK_EQUAL(-120,*( calc().calculation(vecto)));
    }
    TEST(Maximum_Positive) {
        std::vector<int16_t> vecto = {32767, 1};
        CHECK_EQUAL(32767,*( calc().calculation(vecto)));
    }
    TEST(Maximum_Negative) {
        std::vector<int16_t> vecto = {-32768, 1};
        CHECK_EQUAL(-32768,*( calc().calculation(vecto)));
    }
    TEST(More_that_max) {
        std::vector<int16_t> vecto = {32767,2};
        CHECK_THROW(calc().calculation(vecto),name_error);
    }
    TEST(Less_that_min) {
        std::vector<int16_t> vecto = {-32768, 2};
        CHECK_THROW(calc().calculation(vecto),name_error);
    }
    TEST(Negative_and_Positive) {
        std::vector<int16_t> vecto = {1,-2,3,-4};
        CHECK_EQUAL(24,*( calc().calculation(vecto)));
        
    }
    TEST(None) {
        std::vector<int16_t> vecto = {};
        CHECK_THROW(calc().calculation(vecto),name_error);
    }
    
}
int main()
{
    return UnitTest::RunAllTests();
}
