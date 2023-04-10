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
#define FUNC (__func__)

#define IS_TRUE(x) { if (!(x)) std::cout << "IS_TRUE_ERROR: " << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }

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

#define TEST_CLASS_SQRT_VALID_UT1_POS_POS_VAR_1 (6)
#define TEST_CLASS_SQRT_VALID_UT1_POS_POS_VAR_2 (6)

#define TEST_CLASS_SQRT_VALID_UT2_POS_POS_VAR_1 (7)
#define TEST_CLASS_SQRT_VALID_UT2_POS_POS_VAR_2 (7)

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
 * Description: Tests mathematical operation.
 *
 * Valid UT inputs: Any positive or negative integer value (includes: chars and decimals)
 *
 * Invalid UT inputs: Overflow values
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

} /* test_getSum */

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

    IS_TRUE(test1.getSum(a, b) == (a+b))

    /* UT: Positive and Negative */
    a = TEST_CLASS_POS_NEG_VAR_1;
    b = TEST_CLASS_POS_NEG_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getSum(a, b) == (a+b))

    /* UT: Negative and Negative */
    a = TEST_CLASS_NEG_NEG_VAR_1; //changed
    b = TEST_CLASS_NEG_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getSum(a, b) == (a+b))

    /* UT: Negative and Positive */
    a = TEST_CLASS_NEG_POS_VAR_1;
    b = TEST_CLASS_NEG_POS_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getSum(a, b) == (a+b))

    /* UT: Perfect Square */
    a = TEST_CLASS_PERFECT_SQUARE_VAR_1; //changed
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getSum(a, b) == (a+b))

} /* test_valid_getSum */

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
        std::cout << "F:" << FILE << " L:" << LINE << " fn:" << FUNC << " : Expected: catch 'overflow_error' [mVar1=" << a << ", mVar2=" << b << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
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
        std::cout << "F:" << FILE << " L:" << LINE << " fn:" << FUNC << " : Expected: catch 'overflow_error' [mVar1=" << a << ", mVar2=" << b << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
    }

} /* test_invalid_getSum */

/*****************************************************************
 *
 * Function: test_getAverage
 *
 * Description: Tests mathematical operation.
 *
 * Valid UT inputs: Any positive or negative integer value (includes: chars and decimals)
 *
 * Invalid UT inputs: Overflow values
 *
 *****************************************************************/
void TestClass::test_getAverage()
{
    std::cout << std::endl << "Testing Functions::getAverage()" << std::endl;

    std::cout << std::endl << "Testing GOOD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    test_valid_getAverage();
    std::cout << "End..." << std::endl;

    std::cout << std::endl << "Testing BAD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    test_invalid_getAverage();
    std::cout << "End..." << std::endl;

} /* test_getAverage */

/*****************************************************************
 *
 * Function: test_valid_getAverage
 *
 *****************************************************************/
void TestClass::test_valid_getAverage()
{
    /* UT: Positive and Positive */
    int a = TEST_CLASS_POS_POS_VAR_1;
    int b = TEST_CLASS_POS_POS_VAR_2;

    Functions test1;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getAverage(a, b) == ((a+b)/2))

    /* UT: Positive and Negative */
    a = TEST_CLASS_POS_NEG_VAR_1;
    b = TEST_CLASS_POS_NEG_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getAverage(a, b) == ((a+b)/2))

    /* UT: Negative and Negative */
    a = TEST_CLASS_NEG_NEG_VAR_1; //changed
    b = TEST_CLASS_NEG_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getAverage(a, b) == ((a+b)/2))

    /* UT: Negative and Positive */
    a = TEST_CLASS_NEG_POS_VAR_1;
    b = TEST_CLASS_NEG_POS_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getAverage(a, b) == ((a+b)/2))

    /* UT: Perfect Square */
    a = TEST_CLASS_PERFECT_SQUARE_VAR_1; //changed
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getAverage(a, b) == ((a+b)/2))

} /* test_valid_getAverage */

/*****************************************************************
 *
 * Function: test_invalid_getAverage
 *
 *****************************************************************/
void TestClass::test_invalid_getAverage()
{
    Functions test1;

    /* UT: Overflow with positive values */

    int a = INT_MAX;
    int b = TEST_CLASS_POSITIVE_VALUE;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    try
    {
        IS_TRUE(test1.getAverage(a, b) == ((a+b)/2))
    }
    catch (const std::overflow_error& e)
    {
        std::cout << "F:" << FILE << " L:" << LINE << " fn:" << FUNC << " : Expected: catch 'overflow_error' [mVar1=" << a << ", mVar2=" << b << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
    }

    /* UT: Overflow with negative values */

    a = INT_MIN;
    b = TEST_CLASS_NEGATIVE_VALUE;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    try
    {
        IS_TRUE(test1.getAverage(a, b) == ((a+b)/2))
    }
    catch (const std::overflow_error& e)
    {
        std::cout << "F:" << FILE << " L:" << LINE << " fn:" << FUNC << " : Expected: catch 'overflow_error' [mVar1=" << a << ", mVar2=" << b << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
    }

} /* test_invalid_getAverage */


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

} /* test_isAverageWithinDesiredMaxValue */

/*****************************************************************
 *
 * Function: test_getDifference
 *
 * Description: Tests mathematical operation.
 *
 * Valid UT inputs: Any positive or negative integer value (includes: chars and decimals)
 *
 * Invalid UT inputs: Overflow values
 *
 *****************************************************************/
void TestClass::test_getDifference()
{
    std::cout << std::endl << "Testing Functions::getDifference()" << std::endl;

    std::cout << std::endl << "Testing GOOD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    test_valid_getDifference();
    std::cout << "End..." << std::endl;

    std::cout << std::endl << "Testing BAD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    test_invalid_getDifference();
    std::cout << "End..." << std::endl;

} /* test_getDifference */

/*****************************************************************
 *
 * Function: test_valid_getDifference
 *
 *****************************************************************/
void TestClass::test_valid_getDifference()
{
    /* UT: Positive and Positive */
    int a = TEST_CLASS_POS_POS_VAR_1;
    int b = TEST_CLASS_POS_POS_VAR_2;

    Functions test1;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getDifference(a, b) == (a-b))

    /* UT: Positive and Negative */
    a = TEST_CLASS_POS_NEG_VAR_1;
    b = TEST_CLASS_POS_NEG_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getDifference(a, b) == (a-b))

    /* UT: Negative and Negative */
    a = TEST_CLASS_NEG_NEG_VAR_1; //changed
    b = TEST_CLASS_NEG_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getDifference(a, b) == (a-b))

    /* UT: Negative and Positive */
    a = TEST_CLASS_NEG_POS_VAR_1;
    b = TEST_CLASS_NEG_POS_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getDifference(a, b) == (a-b))

    /* UT: Perfect Square */
    a = TEST_CLASS_PERFECT_SQUARE_VAR_1; //changed
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getDifference(a, b) == (a-b))

} /* test_valid_getDifference */

/*****************************************************************
 *
 * Function: test_invalid_getDifference
 *
 *****************************************************************/
void TestClass::test_invalid_getDifference()
{
    Functions test1;

    /* UT: Overflow with positive values */

    int a = INT_MIN;
    int b = TEST_CLASS_POSITIVE_VALUE;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    try
    {
        IS_TRUE(test1.getDifference(a, b) == (a-b))
    }
    catch (const std::overflow_error& e)
    {
        std::cout << "F:" << FILE << " L:" << LINE << " fn:" << FUNC << " : Expected: catch 'overflow_error' [mVar1=" << a << ", mVar2=" << b << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
    }

    /* UT: Overflow with negative values */

    a = INT_MAX;
    b = TEST_CLASS_NEGATIVE_VALUE;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    try
    {
        IS_TRUE(test1.getDifference(a, b) == (a-b))
    }
    catch (const std::overflow_error& e)
    {
        std::cout << "F:" << FILE << " L:" << LINE << " fn:" << FUNC << " : Expected: catch 'overflow_error' [mVar1=" << a << ", mVar2=" << b << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
    }

} /* test_invalid_getDifference */

/*****************************************************************
 *
 * Function: test_getProduct
 *
 * Description: Tests mathematical operation.
 *
 * Valid UT inputs: Any positive or negative integer value (includes: chars and decimals)
 *
 * Invalid UT inputs: Overflow values
 *
 *****************************************************************/
void TestClass::test_getProduct()
{
    std::cout << std::endl << "Testing Functions::getProduct()" << std::endl;

    std::cout << std::endl << "Testing GOOD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    test_valid_getProduct();
    std::cout << "End..." << std::endl;

    std::cout << std::endl << "Testing BAD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    test_invalid_getProduct();
    std::cout << "End..." << std::endl;

} /* test_getProduct */

/*****************************************************************
 *
 * Function: test_valid_getProduct
 *
 *****************************************************************/
void TestClass::test_valid_getProduct()
{
    /* UT: Positive and Positive */
    int a = TEST_CLASS_POS_POS_VAR_1;
    int b = TEST_CLASS_POS_POS_VAR_2;

    Functions test1;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getProduct(a, b) == (a*b))

    /* UT: Positive and Negative */
    a = TEST_CLASS_POS_NEG_VAR_1;
    b = TEST_CLASS_POS_NEG_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getProduct(a, b) == (a*b))

    /* UT: Negative and Negative */
    a = TEST_CLASS_NEG_NEG_VAR_1; //changed
    b = TEST_CLASS_NEG_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getProduct(a, b) == (a*b))

    /* UT: Negative and Positive */
    a = TEST_CLASS_NEG_POS_VAR_1;
    b = TEST_CLASS_NEG_POS_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getProduct(a, b) == (a*b))

    /* UT: Perfect Square */
    a = TEST_CLASS_PERFECT_SQUARE_VAR_1; //changed
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getProduct(a, b) == (a*b))

} /* test_valid_getProduct */

/*****************************************************************
 *
 * Function: test_invalid_getProduct
 *
 *****************************************************************/
void TestClass::test_invalid_getProduct()
{
    Functions test1;

    /* UT: Overflow with positive values */

    int a = INT_MIN;
    int b = INT_MAX;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    try
    {
        IS_TRUE(test1.getProduct(a, b) == (a*b))
    }
    catch (const std::overflow_error& e)
    {
        std::cout << "F:" << FILE << " L:" << LINE << " fn:" << FUNC << " : Expected: catch 'overflow_error' [mVar1=" << a << ", mVar2=" << b << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
    }

    /* UT: Overflow with negative values */

    a = INT_MAX;
    b = TEST_CLASS_NEGATIVE_VALUE;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    try
    {
        IS_TRUE(test1.getProduct(a, b) == (a*b))
    }
    catch (const std::overflow_error& e)
    {
        std::cout << "F:" << FILE << " L:" << LINE << " fn:" << FUNC << " : Expected: catch 'overflow_error' [mVar1=" << a << ", mVar2=" << b << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
    }

} /* test_invalid_getProduct */

/*****************************************************************
 *
 * Function: test_getSquareRootOfProduct
 *
 * Description: Tests mathematical operation.
 *
 * Valid UT inputs: Any positive or negative integer value (includes: chars and decimals)
 *
 * Invalid UT inputs: Negative resulting product
 *
 *****************************************************************/
void TestClass::test_getSquareRootOfProduct()
{
    std::cout << std::endl << "Testing Functions::getSquareRootOfProduct()" << std::endl;

    std::cout << std::endl << "Testing GOOD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    test_valid_getSquareRootOfProduct();
    std::cout << "End..." << std::endl;

    std::cout << std::endl << "Testing BAD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    test_invalid_getSquareRootOfProduct();
    std::cout << "End..." << std::endl;

} /* test_getSquareRootOfProduct */

/*****************************************************************
 *
 * Function: test_valid_getSquareRootOfProduct
 *
 *****************************************************************/
void TestClass::test_valid_getSquareRootOfProduct()
{
    std::cout << std::endl << "Testing Functions::getSquareRootOfProduct()" << std::endl;

    /* UT: Positive and Positive */
    int a = TEST_CLASS_POS_POS_VAR_1;
    int b = TEST_CLASS_POS_POS_VAR_2;

    Functions test1;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getSquareRootOfProduct(a, b) == sqrt(a*b))

    /* UT: Negative and Negative */
    a = TEST_CLASS_NEG_NEG_VAR_1; //changed
    b = TEST_CLASS_NEG_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getSquareRootOfProduct(a, b) == sqrt(a*b))

    /* UT: Perfect Square */
    a = TEST_CLASS_PERFECT_SQUARE_VAR_1; //changed
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getSquareRootOfProduct(a, b) == sqrt(a*b))

} /* test_valid_getSquareRootOfProduct */

/*****************************************************************
 *
 * Function: test_invalid_getSquareRootOfProduct
 *
 *****************************************************************/
void TestClass::test_invalid_getSquareRootOfProduct()
{
    Functions test1;

    /* UT: Overflow with positive values */

    int a = INT_MAX;
    int b = INT_MAX;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    try
    {
        IS_TRUE(test1.getSquareRootOfProduct(a, b) == (a*b))
    }
    catch (const std::overflow_error& e)
    {
        std::cout << "F:" << FILE << " L:" << LINE << " fn:" << FUNC << " : Expected: catch 'overflow_error' [mVar1=" << a << ", mVar2=" << b << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
    }

    /* UT: Overflow with negative values */

    a = INT_MIN;
    b = INT_MAX;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    try
    {
        IS_TRUE(test1.getSquareRootOfProduct(a, b) == (a*b))
    }
    catch (const std::overflow_error& e)
    {
        std::cout << "F:" << FILE << " L:" << LINE << " fn:" << FUNC << " : Expected: catch 'overflow_error' [mVar1=" << a << ", mVar2=" << b << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
    }

    /* UT: Invalid argument with negative product */

    a = TEST_CLASS_POSITIVE_VALUE;
    b = TEST_CLASS_NEGATIVE_VALUE;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    try
    {
        IS_TRUE(test1.getSquareRootOfProduct(a, b) == (a*b))
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "F:" << FILE << " L:" << LINE << " fn:" << FUNC << ": " << "Error: cannot take square root of negative value. [mVar1=" << a << ", mVar2=" << b << ", product=" << (a*b) << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
    }
} /* test_invalid_getSquareRootOfProduct */

/*****************************************************************
 *
 * Function: test_isSquareRootOfProductWithinDesiredMaxValue
 *
 * Description: Tests mathematical operation.
 *
 * Valid UT inputs: Any positive or negative integer value (includes: chars and decimals)
 *
 * Invalid UT inputs: Any positive or negative integer value pairs whose square root is larger than desired max sqrt value.
 *
 *****************************************************************/
void TestClass::test_isSquareRootOfProductWithinDesiredMaxValue()
{
    std::cout << std::endl << "Testing Functions::isSquareRootOfProductWithinDesiredMaxValue()" << std::endl;

    std::cout << std::endl << "Testing GOOD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    test_valid_isSquareRootOfProductWithinDesiredMaxValue();
    std::cout << "End..." << std::endl;

    std::cout << std::endl << "Testing BAD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    test_invalid_isSquareRootOfProductWithinDesiredMaxValue();
    std::cout << "End..." << std::endl;

} /* test_isSquareRootOfProductWithinDesiredMaxValue */

/*****************************************************************
 *
 * Function: test_valid_isSquareRootOfProductWithinDesiredMaxValue
 *
 *****************************************************************/
void TestClass::test_valid_isSquareRootOfProductWithinDesiredMaxValue()
{
    unsigned int d = TEST_CLASS_MAX_SQRT_VALUE;

    Functions test1;
    test1.set_mMax_square_root_value(d);

    /* UT: Positive and Positive */
    int a = TEST_CLASS_SQRT_VALID_UT1_POS_POS_VAR_1;
    int b = TEST_CLASS_SQRT_VALID_UT1_POS_POS_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << ", mMaxSquareRootValue=" << d << std::endl;

    IS_TRUE(test1.isSquareRootOfProductWithinDesiredMaxValue(a, b) == true)

    /* UT: Positive and Positive */
    a = TEST_CLASS_SQRT_VALID_UT2_POS_POS_VAR_1;
    b = TEST_CLASS_SQRT_VALID_UT2_POS_POS_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << ", mMaxSquareRootValue=" << d << std::endl;

    IS_TRUE(test1.isSquareRootOfProductWithinDesiredMaxValue(a, b) == true)

    /* UT: Negative and Negative */
    a = (TEST_CLASS_SQRT_VALID_UT1_POS_POS_VAR_1 * -1);
    b = (TEST_CLASS_SQRT_VALID_UT1_POS_POS_VAR_2 * -1);

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << ", mMaxSquareRootValue=" << d << std::endl;

    IS_TRUE(test1.isSquareRootOfProductWithinDesiredMaxValue(a, b) == true)

    /* UT: Negative and Negative */
    a = (TEST_CLASS_SQRT_VALID_UT2_POS_POS_VAR_1 * -1);
    b = (TEST_CLASS_SQRT_VALID_UT2_POS_POS_VAR_2 * -1);

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << ", mMaxSquareRootValue=" << d << std::endl;

    IS_TRUE(test1.isSquareRootOfProductWithinDesiredMaxValue(a, b) == true)

} /* test_valid_isSquareRootOfProductWithinDesiredMaxValue */

/*****************************************************************
 *
 * Function: test_invalid_isSquareRootOfProductWithinDesiredMaxValue
 *
 *****************************************************************/
void TestClass::test_invalid_isSquareRootOfProductWithinDesiredMaxValue()
{
    unsigned int d = TEST_CLASS_MAX_SQRT_VALUE;

    Functions test1;
    test1.set_mMax_square_root_value(d);

    /* UT: Positive and Positive */
    int a = TEST_CLASS_POS_POS_VAR_1;
    int b = TEST_CLASS_POS_POS_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << ", mMaxSquareRootValue=" << d << std::endl;

    IS_TRUE(test1.isSquareRootOfProductWithinDesiredMaxValue(a, b) == true)

    /* UT: Negative and Negative */
    a = TEST_CLASS_NEG_NEG_VAR_1;
    b = TEST_CLASS_NEG_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << ", mMaxSquareRootValue=" << d << std::endl;

    IS_TRUE(test1.isSquareRootOfProductWithinDesiredMaxValue(a, b) == true)

    /* UT: Perfect Square */
    a = TEST_CLASS_PERFECT_SQUARE_VAR_1;
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << ", mMaxSquareRootValue=" << d << std::endl;

    IS_TRUE(test1.isSquareRootOfProductWithinDesiredMaxValue(a, b) == true)

} /* test_invalid_isSquareRootOfProductWithinDesiredMaxValue */

/*****************************************************************
 *
 * Function: test_getDividedValue
 *
 * Description: Tests mathematical operation.
 *
 * Valid UT inputs: Any positive or negative integer value (includes: chars and decimals)
 *
 * Invalid UT inputs: Overflow values
 *
 *****************************************************************/
void TestClass::test_getDividedValue()
{
    std::cout << std::endl << "Testing Functions::getDividedValue()" << std::endl;

    std::cout << std::endl << "Testing GOOD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    test_valid_getDividedValue();
    std::cout << "End..." << std::endl;

    std::cout << std::endl << "Testing BAD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    test_invalid_getDividedValue();
    std::cout << "End..." << std::endl;

} /* test_getDividedValue */

/*****************************************************************
 *
 * Function: test_valid_getDividedValue
 *
 *****************************************************************/
void TestClass::test_valid_getDividedValue()
{
    std::cout << std::endl << "Testing Functions::getDividedValue()" << std::endl;

    /* UT: Positive and Positive */
    int a = TEST_CLASS_POS_POS_VAR_1;
    int b = TEST_CLASS_POS_POS_VAR_2;

    Functions test1;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getDividedValue(a, b) == (a*1.0/b))

    /* UT: Positive and Negative */
    a = TEST_CLASS_POS_NEG_VAR_1;
    b = TEST_CLASS_POS_NEG_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getDividedValue(a, b) == (a*1.0/b))

    /* UT: Negative and Negative */
    a = TEST_CLASS_NEG_NEG_VAR_1; //changed
    b = TEST_CLASS_NEG_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getDividedValue(a, b) == (a*1.0/b))

    /* UT: Negative and Positive */
    a = TEST_CLASS_NEG_POS_VAR_1;
    b = TEST_CLASS_NEG_POS_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getDividedValue(a, b) == (a*1.0/b))

    /* UT: Perfect Square */
    a = TEST_CLASS_PERFECT_SQUARE_VAR_1; //changed
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getDividedValue(a, b) == (a*1.0/b))

    /* UT: Divide zero by number */
    a = 0; //changed
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getDividedValue(a, b) == (a*1.0/b))

} /* test_valid_getDividedValue */

/*****************************************************************
 *
 * Function: test_invalid_getDividedValue
 *
 *****************************************************************/
void TestClass::test_invalid_getDividedValue()
{
    Functions test1;

    /* UT: Overflow with INT_MIN and negative value */

    int a = INT_MIN;
    int b = -1;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    try
    {
        IS_TRUE(test1.getDividedValue(a, b) == (a*1.0/b))
    }
    catch (const std::overflow_error& e)
    {
        std::cout << "F:" << FILE << " L:" << LINE << " fn:" << FUNC << " : Expected: catch 'overflow_error' [mVar1=" << a << ", mVar2=" << b << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
    }

    /* UT: Divide by zero. */

    a = TEST_CLASS_POSITIVE_VALUE;
    b = 0;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    double divided_value = test1.getDividedValue(a, b);
    IS_TRUE(divided_value != (a*1.0/b))

    if (divided_value == 0.0)
    {
        std::cout << "F:" << FILE << " L:" << LINE << " fn:" << FUNC << " : Expected, as second argument is zero. [mVar1=" << a << ", mVar2=" << b << "]." <<  " .....PASS" << std::endl;
    }

} /* test_invalid_getDividedValue */

/*****************************************************************
 *
 * Function: test_calculateQuotientAndRemainder
 *
 * Description: Tests mathematical operation.
 *
 * Valid UT inputs: Any positive or negative integer value (includes: chars and decimals)
 *
 * Invalid UT inputs: None
 *
 *****************************************************************/
void TestClass::test_calculateQuotientAndRemainder()
{
    std::cout << std::endl << "Testing Functions::calculateQuotientAndRemainder()" << std::endl;

    std::cout << std::endl << "Testing GOOD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    test_valid_calculateQuotientAndRemainder();
    std::cout << "End..." << std::endl;

    std::cout << std::endl << "Testing BAD Weather..." << std::endl;
    std::cout << "Start..." << std::endl;
    test_invalid_calculateQuotientAndRemainder();
    std::cout << "End..." << std::endl;

} /* test_calculateQuotientAndRemainder */

/*****************************************************************
 *
 * Function: test_valid_calculateQuotientAndRemainder
 *
 *****************************************************************/
void TestClass::test_valid_calculateQuotientAndRemainder()
{
    /* UT: Positive and Positive */
    int a = 0;
    int b = TEST_CLASS_POS_POS_VAR_2;

    Functions test1;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getQuotient(a, b) == (a/b))
    IS_TRUE(test1.getRemainder(a, b) == (a%b))

    /* UT: Positive and Positive */
    a = TEST_CLASS_POS_POS_VAR_1;
    b = TEST_CLASS_POS_POS_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getQuotient(a, b) == (a/b))
    IS_TRUE(test1.getRemainder(a, b) == (a%b))

    /* UT: Positive and Negative */
    a = TEST_CLASS_POS_NEG_VAR_1;
    b = TEST_CLASS_POS_NEG_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getQuotient(a, b) == (a/b))
    IS_TRUE(test1.getRemainder(a, b) == (a%b))

    /* UT: Negative and Negative */
    a = TEST_CLASS_NEG_NEG_VAR_1; //changed
    b = TEST_CLASS_NEG_NEG_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getQuotient(a, b) == (a/b))
    IS_TRUE(test1.getRemainder(a, b) == (a%b))

    /* UT: Negative and Positive */
    a = TEST_CLASS_NEG_POS_VAR_1;
    b = TEST_CLASS_NEG_POS_VAR_2; //changed

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getQuotient(a, b) == (a/b))
    IS_TRUE(test1.getRemainder(a, b) == (a%b))

    /* UT: Perfect Square */
    a = TEST_CLASS_PERFECT_SQUARE_VAR_1; //changed
    b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    IS_TRUE(test1.getQuotient(a, b) == (a/b))
    IS_TRUE(test1.getRemainder(a, b) == (a%b))

} /* test_valid_calculateQuotientAndRemainder */

/*****************************************************************
 *
 * Function: test_invalid_calculateQuotientAndRemainder
 *
 *****************************************************************/
void TestClass::test_invalid_calculateQuotientAndRemainder()
{
    Functions test1;

    /* UT: Test divide by zero */
    int a = TEST_CLASS_POS_POS_VAR_1;
    int b = 0;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    try
    {
        IS_TRUE(test1.getQuotient(a, b) == (a/b))
        IS_TRUE(test1.getRemainder(a, b) == (a%b))
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "F:" << FILE << " L:" << LINE << " fn:" << FUNC << " : Expected: catch 'invalid_argument' [mVar1=" << a << ", mVar2=" << b << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
    }


    /* UT: Test overflow with INT_MIN and -1 */
    a = INT_MIN;
    b = -1;

    std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

    try
    {
        IS_TRUE(test1.getQuotient(a, b) == (a/b))
        IS_TRUE(test1.getRemainder(a, b) == (a%b))
    }
    catch (const std::overflow_error& e)
    {
        std::cout << "F:" << FILE << " L:" << LINE << " fn:" << FUNC << " : Expected: catch 'overflow_error' [mVar1=" << a << ", mVar2=" << b << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
    }

} /* test_invalid_calculateQuotientAndRemainder */


int main()
{
    print_log(FILE, LINE, "Test print");

    TestClass myTest;
    myTest.test_getSum();
    myTest.test_getAverage();
    myTest.test_isAverageWithinDesiredMaxValue();
    myTest.test_getDifference();
    myTest.test_getProduct();
    myTest.test_getSquareRootOfProduct();
    myTest.test_isSquareRootOfProductWithinDesiredMaxValue();
    myTest.test_getDividedValue();
    myTest.test_calculateQuotientAndRemainder();

    return 0;
}

#endif
