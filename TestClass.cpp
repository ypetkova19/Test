#include <iostream>
#include <math.h> //check c++ version - check syntax
#include <cassert> //check c++ version - check syntax
#include <string>
#include <stdexcept>
#include <limits>

#include "Functions.hpp"

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

//ADD HEADER FOR TESTCLASS

class TestClass
{
    private:
        int mVar1;
        int mVar2;
        int mMax_average_value;
        unsigned int mMax_square_root_value;

    public:
        TestClass()
        {
            mVar1 = 0;
            mVar2 = 0;
            mMax_average_value = 0;
            mMax_square_root_value = 0;
            std::cout << std::endl << "TestClass Default Constructor created" << std::endl;
        }

        TestClass(int a, int b, int c, unsigned int d): mVar1(a), mVar2(b), mMax_average_value(c), mMax_square_root_value(d)
        {
            std::cout << "TestClass Constructor created. mVar1=" << mVar1 << ", mVar2="<< mVar2 << ", mMax_average_value="<< mMax_average_value << ", mMax_square_root_value="<< mMax_square_root_value << std::endl << std::endl;
        }

        void test_getSum()
        {
            std::cout << std::endl << "Testing Functions::getSum()" << std::endl;

            /* UT: Positive and Positive */
            int a = TEST_CLASS_POS_POS_VAR_1;
            int b = TEST_CLASS_POS_POS_VAR_2;

            Functions test1;

            std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

            test1.set_mVar1(a);
            test1.set_mVar2(b);
            IS_TRUE(test1.getSum(a, b) == (a+b))

            /* UT: Positive and Negative */
            a = TEST_CLASS_POS_NEG_VAR_1;
            b = TEST_CLASS_POS_NEG_VAR_2; //changed

            std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

            test1.set_mVar2(b);
            IS_TRUE(test1.getSum(a, b) == (a+b))

            /* UT: Negative and Negative */
            a = TEST_CLASS_NEG_NEG_VAR_1; //changed
            b = TEST_CLASS_NEG_NEG_VAR_2;

            std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

            test1.set_mVar1(a);
            IS_TRUE(test1.getSum(a, b) == (a+b))

            /* UT: Negative and Positive */
            a = TEST_CLASS_NEG_POS_VAR_1;
            b = TEST_CLASS_NEG_POS_VAR_2; //changed

            std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

            test1.set_mVar2(b);
            IS_TRUE(test1.getSum(a, b) == (a+b))

            /* UT: Perfect Square */
            a = TEST_CLASS_PERFECT_SQUARE_VAR_1; //changed
            b = TEST_CLASS_PERFECT_SQUARE_VAR_2;

            std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

            test1.set_mVar1(a);
            IS_TRUE(test1.getSum(a, b) == (a+b))
        }

        void test_getAverage()
        {
            std::cout << std::endl << "Testing Functions::getAverage()" << std::endl;

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

        void test_isAverageWithinDesiredMaxValue()
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

        void test_getDifference()
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

        void test_getProduct()
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

        void test_getSquareRootOfProduct()
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

        void test_isSquareRootOfProductWithinDesiredMaxValue()
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

        void test_getDividedValue()
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

        void test_calculateQuotientAndRemainder()
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

#if 0 // AS PER OUR CALL WITH ADI.
            int quotient;
            int remainder;

            std::cout << "Testing with mVar1=" << a << ", mVar2=" << b << std::endl;

            Functions test1;
            test1.set_mVar1(a);
            test1.set_mVar2(b);
            try
            {
                test1.getQuotientAndRemainder(a, b, quotient, remainder);
            }
            catch (std::invalid_argument& e)
            {
                std::cerr << e.what() << std::endl;
                return;
            }

            IS_TRUE(quotient == (a/b))
            IS_TRUE(remainder == (a%b))
#endif
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
};

int main()
{
    print_log(FILE, LINE, "Test print");

    // int a;
    // int b;

    // std::cout << "Enter first integer value: ";
    // std::cin >> a;
    // std::cout << "Enter second integer value: ";
    // std::cin >> b;

    // std::cout << "Working with integers: " << a << " and " << b << std::endl;

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

#if 0
    /* create object of type Functions */
    Functions test1;
    test1.set_mVar1(a);
    test1.set_mVar2(b);
    std::cout << "Sum: " << test1.getSum(a, b) << std::endl;
    IS_TRUE(test1.getSum(a, b) == (a+b))

    std::cout << "Difference: " << test1.getDifference(a, b) << std::endl;
    IS_TRUE(test1.getDifference(a, b) == (a-b))

    std::cout << "Product: " << test1.getProduct(a, b) << std::endl;
    IS_TRUE(test1.getProduct(a, b) == (a*b))

    int quotient;
    int remainder;
    test1.calculateQuotientAndRemainder(a, b, quotient, remainder);

    std::cout << "Quotient: " << quotient << ", Remainder: " << remainder << std::endl;

    std::cout << "Divided value: " << test1.getDividedValue(a, b) << std::endl;
    IS_TRUE(test1.getDividedValue(a, b) == (a*1.0/b))

    std::cout << "Average: " << test1.getAverage(a, b) << std::endl;
    IS_TRUE(test1.getAverage(a, b) == ((a+b)/2))

    std::cout << "Average is " << ((test1.isAverageWithinDesiredMaxValue(a, b) == true) ? "WITHIN" : "OUTSIDE OF") << " max_average_value. [max_average_value=" << test1.get_mMax_average_value() << "]" << std::endl;

    std::cout << "Square root: " << test1.getSquareRootOfProduct(a, b) << std::endl;
    IS_TRUE(test1.getSquareRootOfProduct(a, b) == (sqrt(a*b)))
    // std::cout << "getSquareRootOfProduct(a*b): " << test1.getSquareRootOfProduct(a, b) << ", sqrt(a*b): " << sqrt(a*b) << std::endl;

    std::cout << "Square root is " << ((test1.isSquareRootOfProductWithinDesiredMaxValue(a, b) == true) ? "WITHIN" : "OUTSIDE OF") << " max_square_root_value. [max_square_root_value=" << test1.get_mMax_square_root_value() << "]" << std::endl;
#endif
    return 0;
}
