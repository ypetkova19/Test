/************************************************
 * File       : TestClass.hpp
 * Description: This file contains function
 *              prototypes.
 ************************************************/
#include <string>

class TestClass
{
    private:
        int mVar1;
        int mVar2;
        int mMax_average_value;
        unsigned int mMax_square_root_value;

    public:
        TestClass();
        TestClass(int var1, int var2, int max_average_value, unsigned int max_sqrt_value);;

        /* Methods */

        void test_getSum();
        void test_valid_getSum();
        void test_invalid_getSum();

        void test_getAverage();
        void test_valid_getAverage();
        void test_invalid_getAverage();
        void test_isAverageWithinDesiredMaxValue();

        void test_getDifference();
        void test_valid_getDifference();
        void test_invalid_getDifference();

        void test_getProduct();
        void test_valid_getProduct();
        void test_invalid_getProduct();

        void test_getSquareRootOfProduct();
        void test_valid_getSquareRootOfProduct();
        void test_invalid_getSquareRootOfProduct();
        void test_isSquareRootOfProductWithinDesiredMaxValue();
        void test_valid_isSquareRootOfProductWithinDesiredMaxValue();
        void test_invalid_isSquareRootOfProductWithinDesiredMaxValue();

        void test_getDividedValue();
        void test_valid_getDividedValue();
        void test_invalid_getDividedValue();

        void test_calculateQuotientAndRemainder();
        void test_valid_calculateQuotientAndRemainder();
        void test_invalid_calculateQuotientAndRemainder();
};
