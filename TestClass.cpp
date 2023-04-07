#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
#include <stdexcept>
#include <limits>

#include "Functions.hpp"
#include "TestClass.hpp"

#ifndef TESTCLASS_HPP_INCLUDED
#define TESTCLASS_HPP_INCLUDED

#define FILE (__FILE__)
#define LINE (__LINE__)

#define IS_TRUE(x) { if (!(x)) std::cout << "ERROR: " << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }

#define TEST_CLASS_POS_POS_VAR_1 (8)
#define TEST_CLASS_POS_POS_VAR_2 (9)

#define TEST_CLASS_POS_NEG_VAR_1 (8)
#define TEST_CLASS_POS_NEG_VAR_2 (-9)

#define TEST_CLASS_NEG_NEG_VAR_1 (-8)
#define TEST_CLASS_NEG_NEG_VAR_2 (-9)

#define TEST_CLASS_NEG_POS_VAR_1 (-8)
#define TEST_CLASS_NEG_POS_VAR_2 (9)

#define TEST_CLASS_PERFECT_SQUARE_VAR_1 (9)
#define TEST_CLASS_PERFECT_SQUARE_VAR_2 (9)

#define TEST_CLASS_MAX_AVERAGE_VALUE (10)
#define TEST_CLASS_MAX_SQRT_VALUE (7)

#define TEST_CLASS_CHAR_VALUE ('a')
#define TEST_CLASS_DOUBLE_VALUE (3.14159)
#define TEST_CLASS_POSITIVE_VALUE (5)
#define TEST_CLASS_NEGATIVE_VALUE (-5)


TestClass::TestClass()
{
    mVar1 = 0;
    mVar2 = 0;
    mMax_average_value = 0;
    mMax_square_root_value = 0;
    std::cout << std::endl << "TestClass Default Constructor created" << std::endl;
}

TestClass::TestClass(int a, int b, int c, unsigned int d): mVar1(a), mVar2(b), mMax_average_value(c), mMax_square_root_value(d)
{
    std::cout << "TestClass Constructor created. mVar1=" << mVar1 << ", mVar2="<< mVar2 << ", mMax_average_value="<< mMax_average_value << ", mMax_square_root_value="<< mMax_square_root_value << std::endl << std::endl;
}

/*****************************************************************
 *
 * Function: test_getSum
 *
 * Description: Tests sum mathematic operation.
 *
 * Valid UT inputs: Any positive or negative integer value (includes: chars and decimals)
 *
 * Invalid UT inputs: None
 *
 *****************************************************************/
void TestClass::test_getSum()
{
    std::cout << std::endl << "Testing Functions::getSum()" << std::endl;

    std::cout << std::endl << "Testing GOOD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    test_valid_getSum();
    std::cout << "End..." << std::endl;

    std::cout << std::endl << "Testing BAD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    test_invalid_getSum();
    std::cout << "End..." << std::endl;
}

/*****************************************************************
 *
 * Function: test_valid_getSum
 *
 *****************************************************************/
void TestClass::test_valid_getSum()
{
    /* UT: Positive and Positive */
    int a = TEST_CLASS_POS_POS_VAR_1;
    int b = TEST_CLASS_POS_POS_VAR_2;

    Functions test1;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    // test1.set_mVar1(a);
    // test1.set_mVar2(b);
    IS_TRUE(test1.getSum(a, b) == (a+b))

    /* UT: Positive and Negative */
    a = TEST_CLASS_POS_NEG_VAR_1;
    b = TEST_CLASS_POS_NEG_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    // test1.set_mVar2(b);
    IS_TRUE(test1.getSum(a, b) == (a+b))

    /* UT: Negative and Negative */
    a = TEST_CLASS_NEG_NEG_VAR_1; //changed
    b = TEST_CLASS_NEG_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    // test1.set_mVar1(a);
    IS_TRUE(test1.getSum(a, b) == (a+b))

    /* UT: Negative and Positive */
    a = TEST_CLASS_NEG_POS_VAR_1;
    b = TEST_CLASS_NEG_POS_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    // test1.set_mVar2(b);
    IS_TRUE(test1.getSum(a, b) == (a+b))

    /* UT: Perfect Square */
    a = TEST_CLASS_PERFECT_SQUARE_VAR_1; //changed
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    // test1.set_mVar1(a);
    IS_TRUE(test1.getSum(a, b) == (a+b))

}

/*****************************************************************
 *
 * Function: test_invalid_getSum
 *
 *****************************************************************/
void TestClass::test_invalid_getSum()
{
    Functions test1;

    /* UT: Overflow with positive values */

    int a = INT_MAX;
    int b = TEST_CLASS_POSITIVE_VALUE;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    try
    {
        IS_TRUE(test1.getSum(a, b) == (a+b))
    }
    catch (const std::overflow_error& e)
    {
        std::cout << "F:" << FILE << " L:" << LINE << " : Expected: catch 'overflow_error' [mVar1=" << a << ", mVar2=" << b << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
    }

    /* UT: Overflow with negative values */

    a = INT_MIN;
    b = TEST_CLASS_NEGATIVE_VALUE;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    try
    {
        IS_TRUE(test1.getSum(a, b) == (a+b))
    }
    catch (const std::overflow_error& e)
    {
        std::cout << "F:" << FILE << " L:" << LINE << " : Expected: catch 'overflow_error' [mVar1=" << a << ", mVar2=" << b << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
    }
}

/*****************************************************************
 *
 * Function: test_getAverage
 *
 * Description: Tests sum mathematic operation.
 *
 * Valid UT inputs: Any positive or negative integer value (includes: chars and decimals)
 *
 * Invalid UT inputs: None
 *
 *****************************************************************/
void TestClass::test_getAverage()
{
    std::cout << std::endl << "Testing Functions::getAverage()" << std::endl;

    std::cout << std::endl << "Testing GOOD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    // test_valid_getAverage();
    std::cout << "End..." << std::endl;

    std::cout << std::endl << "Testing BAD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    // test_invalid_getAverage();
    std::cout << "End..." << std::endl;


    /* UT: Positive and Positive */
    int a = TEST_CLASS_POS_POS_VAR_1;
    int b = TEST_CLASS_POS_POS_VAR_2;

    Functions test1;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    test1.set_mVar2(b);
    IS_TRUE(test1.getAverage(a, b) == ((a+b)/2))

    /* UT: Positive and Negative */
    a = TEST_CLASS_POS_NEG_VAR_1;
    b = TEST_CLASS_POS_NEG_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar2(b);
    IS_TRUE(test1.getAverage(a, b) == ((a+b)/2))

    /* UT: Negative and Negative */
    a = TEST_CLASS_NEG_NEG_VAR_1; //changed
    b = TEST_CLASS_NEG_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    IS_TRUE(test1.getAverage(a, b) == ((a+b)/2))

    /* UT: Negative and Positive */
    a = TEST_CLASS_NEG_POS_VAR_1;
    b = TEST_CLASS_NEG_POS_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar2(b);
    IS_TRUE(test1.getAverage(a, b) == ((a+b)/2))

    /* UT: Perfect Square */
    a = TEST_CLASS_PERFECT_SQUARE_VAR_1; //changed
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    IS_TRUE(test1.getAverage(a, b) == ((a+b)/2))
}

void TestClass::test_isAverageWithinDesiredMaxValue()
{
    std::cout << std::endl << "Testing Functions::isAverageWithinDesiredMaxValue()" << std::endl;

    unsigned int c = TEST_CLASS_MAX_AVERAGE_VALUE;

    Functions test1;
    test1.set_mMax_average_value(c);

    /* UT: Positive and Positive */
    int a = TEST_CLASS_POS_POS_VAR_1;
    int b = TEST_CLASS_POS_POS_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << ", mMaxSquareRootValue=" << c << std::endl;

    test1.set_mVar1(a);
    test1.set_mVar2(b);
    IS_TRUE(test1.isAverageWithinDesiredMaxValue(a, b) == true)

}

void TestClass::test_getDifference()
{
    std::cout << std::endl << "Testing Functions::getDifference()" << std::endl;

    /* UT: Positive and Positive */
    int a = TEST_CLASS_POS_POS_VAR_1;
    int b = TEST_CLASS_POS_POS_VAR_2;

    Functions test1;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    test1.set_mVar2(b);
    IS_TRUE(test1.getDifference(a, b) == (a-b))

    /* UT: Positive and Negative */
    a = TEST_CLASS_POS_NEG_VAR_1;
    b = TEST_CLASS_POS_NEG_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar2(b);
    IS_TRUE(test1.getDifference(a, b) == (a-b))

    /* UT: Negative and Negative */
    a = TEST_CLASS_NEG_NEG_VAR_1; //changed
    b = TEST_CLASS_NEG_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    IS_TRUE(test1.getDifference(a, b) == (a-b))

    /* UT: Negative and Positive */
    a = TEST_CLASS_NEG_POS_VAR_1;
    b = TEST_CLASS_NEG_POS_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar2(b);
    IS_TRUE(test1.getDifference(a, b) == (a-b))

    /* UT: Perfect Square */
    a = TEST_CLASS_PERFECT_SQUARE_VAR_1; //changed
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    IS_TRUE(test1.getDifference(a, b) == (a-b))
}

void TestClass::test_getProduct()
{
    std::cout << std::endl << "Testing Functions::getProduct()" << std::endl;

    /* UT: Positive and Positive */
    int a = TEST_CLASS_POS_POS_VAR_1;
    int b = TEST_CLASS_POS_POS_VAR_2;

    Functions test1;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    test1.set_mVar2(b);
    IS_TRUE(test1.getProduct(a, b) == (a*b))

    /* UT: Positive and Negative */
    a = TEST_CLASS_POS_NEG_VAR_1;
    b = TEST_CLASS_POS_NEG_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar2(b);
    IS_TRUE(test1.getProduct(a, b) == (a*b))

    /* UT: Negative and Negative */
    a = TEST_CLASS_NEG_NEG_VAR_1; //changed
    b = TEST_CLASS_NEG_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    IS_TRUE(test1.getProduct(a, b) == (a*b))

    /* UT: Negative and Positive */
    a = TEST_CLASS_NEG_POS_VAR_1;
    b = TEST_CLASS_NEG_POS_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar2(b);
    IS_TRUE(test1.getProduct(a, b) == (a*b))

    /* UT: Perfect Square */
    a = TEST_CLASS_PERFECT_SQUARE_VAR_1; //changed
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    IS_TRUE(test1.getProduct(a, b) == (a*b))
}

void TestClass::test_getSquareRootOfProduct()
{
    std::cout << std::endl << "Testing Functions::getSquareRootOfProduct()" << std::endl;

    /* UT: Positive and Positive */
    int a = TEST_CLASS_POS_POS_VAR_1;
    int b = TEST_CLASS_POS_POS_VAR_2;

    Functions test1;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    test1.set_mVar2(b);
    IS_TRUE(test1.getSquareRootOfProduct(a, b) == sqrt(a*b))

    /* UT: Positive and Negative */
    a = TEST_CLASS_POS_NEG_VAR_1;
    b = TEST_CLASS_POS_NEG_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar2(b);
    IS_TRUE(test1.getSquareRootOfProduct(a, b) == sqrt(a*b))

    /* UT: Negative and Negative */
    a = TEST_CLASS_NEG_NEG_VAR_1; //changed
    b = TEST_CLASS_NEG_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    IS_TRUE(test1.getSquareRootOfProduct(a, b) == sqrt(a*b))

    /* UT: Negative and Positive */
    a = TEST_CLASS_NEG_POS_VAR_1;
    b = TEST_CLASS_NEG_POS_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar2(b);
    IS_TRUE(test1.getSquareRootOfProduct(a, b) == sqrt(a*b))

    /* UT: Perfect Square */
    a = TEST_CLASS_PERFECT_SQUARE_VAR_1; //changed
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    IS_TRUE(test1.getSquareRootOfProduct(a, b) == sqrt(a*b))
}

void TestClass::test_isSquareRootOfProductWithinDesiredMaxValue()
{
    std::cout << std::endl << "Testing Functions::isSquareRootOfProductWithinDesiredMaxValue()" << std::endl;

    unsigned int d = TEST_CLASS_MAX_SQRT_VALUE;

    Functions test1;
    test1.set_mMax_square_root_value(d);

    /* UT: Positive and Positive */
    int a = TEST_CLASS_POS_POS_VAR_1;
    int b = TEST_CLASS_POS_POS_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << ", mMaxSquareRootValue=" << d << std::endl;

    test1.set_mVar1(a);
    test1.set_mVar2(b);
    IS_TRUE(test1.isSquareRootOfProductWithinDesiredMaxValue(a, b) == true)

    /* UT: Positive and Negative */
    a = TEST_CLASS_POS_NEG_VAR_1;
    b = TEST_CLASS_POS_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << ", mMaxSquareRootValue=" << d << std::endl;

    test1.set_mVar1(a);
    test1.set_mVar2(b);
    IS_TRUE(test1.isSquareRootOfProductWithinDesiredMaxValue(a, b) == true)

    /* UT: Negative and Negative */
    a = TEST_CLASS_NEG_NEG_VAR_1;
    b = TEST_CLASS_NEG_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << ", mMaxSquareRootValue=" << d << std::endl;

    test1.set_mVar1(a);
    test1.set_mVar2(b);
    IS_TRUE(test1.isSquareRootOfProductWithinDesiredMaxValue(a, b) == true)

    /* UT: Negative and Positive */
    a = TEST_CLASS_NEG_POS_VAR_1;
    b = TEST_CLASS_NEG_POS_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << ", mMaxSquareRootValue=" << d << std::endl;

    test1.set_mVar1(a);
    test1.set_mVar2(b);
    IS_TRUE(test1.isSquareRootOfProductWithinDesiredMaxValue(a, b) == true)

    /* UT: Perfect Square */
    a = TEST_CLASS_PERFECT_SQUARE_VAR_1;
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << ", mMaxSquareRootValue=" << d << std::endl;

    test1.set_mVar1(a);
    test1.set_mVar2(b);
    IS_TRUE(test1.isSquareRootOfProductWithinDesiredMaxValue(a, b) == true)

}

void TestClass::test_getDividedValue()
{
    std::cout << std::endl << "Testing Functions::getDividedValue()" << std::endl;

    /* UT: Positive and Positive */
    int a = TEST_CLASS_POS_POS_VAR_1;
    int b = TEST_CLASS_POS_POS_VAR_2;

    Functions test1;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    test1.set_mVar2(b);
    IS_TRUE(test1.getDividedValue(a, b) == (a*1.0/b))

    /* UT: Positive and Negative */
    a = TEST_CLASS_POS_NEG_VAR_1;
    b = TEST_CLASS_POS_NEG_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar2(b);
    IS_TRUE(test1.getDividedValue(a, b) == (a*1.0/b))

    /* UT: Negative and Negative */
    a = TEST_CLASS_NEG_NEG_VAR_1; //changed
    b = TEST_CLASS_NEG_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    IS_TRUE(test1.getDividedValue(a, b) == (a*1.0/b))

    /* UT: Negative and Positive */
    a = TEST_CLASS_NEG_POS_VAR_1;
    b = TEST_CLASS_NEG_POS_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar2(b);
    IS_TRUE(test1.getDividedValue(a, b) == (a*1.0/b))

    /* UT: Perfect Square */
    a = TEST_CLASS_PERFECT_SQUARE_VAR_1; //changed
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    IS_TRUE(test1.getDividedValue(a, b) == (a*1.0/b))
}

void TestClass::test_calculateQuotientAndRemainder()
{
    std::cout << std::endl << "Testing Functions::test_calculateQuotientAndRemainder()" << std::endl;

    /* UT: Positive and Positive */
    int a = TEST_CLASS_POS_POS_VAR_1;
    int b = TEST_CLASS_POS_POS_VAR_2;

    Functions test1;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    test1.set_mVar2(b);
    IS_TRUE(test1.getQuotient(a, b) == (a/b))
    IS_TRUE(test1.getRemainder(a, b) == (a%b))

    /* UT: Positive and Negative */
    a = TEST_CLASS_POS_NEG_VAR_1;
    b = TEST_CLASS_POS_NEG_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar2(b);
    IS_TRUE(test1.getQuotient(a, b) == (a/b))
    IS_TRUE(test1.getRemainder(a, b) == (a%b))

    /* UT: Negative and Negative */
    a = TEST_CLASS_NEG_NEG_VAR_1; //changed
    b = TEST_CLASS_NEG_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    IS_TRUE(test1.getQuotient(a, b) == (a/b))
    IS_TRUE(test1.getRemainder(a, b) == (a%b))

    /* UT: Negative and Positive */
    a = TEST_CLASS_NEG_POS_VAR_1;
    b = TEST_CLASS_NEG_POS_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar2(b);
    IS_TRUE(test1.getQuotient(a, b) == (a/b))
    IS_TRUE(test1.getRemainder(a, b) == (a%b))

    /* UT: Perfect Square */
    a = TEST_CLASS_PERFECT_SQUARE_VAR_1; //changed
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    test1.set_mVar1(a);
    IS_TRUE(test1.getQuotient(a, b) == (a/b))
    IS_TRUE(test1.getRemainder(a, b) == (a%b))
}


int main()
{
    print_log(FILE, LINE, "Test print");

    TestClass myTest;
    myTest.test_getSum();
    // myTest.test_getAverage();
    // myTest.test_isAverageWithinDesiredMaxValue();
    // myTest.test_getDifference();
    // myTest.test_getProduct();
    // myTest.test_getSquareRootOfProduct();
    // myTest.test_isSquareRootOfProductWithinDesiredMaxValue();
    // myTest.test_getDividedValue();
    // myTest.test_calculateQuotientAndRemainder();

    return 0;
}

#endif
