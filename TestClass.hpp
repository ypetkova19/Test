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
        TestClass(int a, int b, int c, unsigned int d);

        /* Methods */

        void test_getSum();
        void test_valid_getSum();
        void test_invalid_getSum();

        void test_getAverage();
        void test_isAverageWithinDesiredMaxValue();
        void test_getDifference();
        void test_getProduct();
        void test_getSquareRootOfProduct();
        void test_isSquareRootOfProductWithinDesiredMaxValue();
        void test_getDividedValue();
        void test_calculateQuotientAndRemainder();
};
