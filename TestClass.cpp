#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
#include <stdexcept>
#include "Functions.hpp"

#define FILE (__FILE__)
#define LINE (__LINE__)

#define IS_TRUE(x) { if (!(x)) std::cout << "ERROR: " << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }

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
            std::cout << "Default Constructor created" << std::endl;
        }

        TestClass(int a, int b): mVar1(a), mVar2(b)
        {
            mMax_average_value = 10;
            mMax_square_root_value = 7;
            std::cout << "Constructor created. mVar1=" << mVar1 << " mVar2="<< mVar2 << std::endl;
        }

        bool test_getSum(int a, int b)
        {
            std::cout << "Testing Functions::getSum()" << std::endl;
            // return IS_TRUE((Functions::getSum(a, b)) == (a+b))
            return true;
        }
};

int main()
{
    print_log(FILE, LINE, "Test print");

    int a;
    int b;

    std::cout << "Enter first integer value: ";
    std::cin >> a;
    std::cout << "Enter second integer value: ";
    std::cin >> b;

    std::cout << "Working with integers: " << a << " and " << b << std::endl;

    /* create object of type Functions */
    Functions test1(a, b);
    std::cout << "Sum: " << test1.getSum(a, b) << std::endl;
    IS_TRUE(test1.getSum(a, b) == (a+b))

    std::cout << "Difference: " << test1.getDifference(a, b) << std::endl;
    IS_TRUE(test1.getDifference(a, b) == (a-b))

    std::cout << "Product: " << test1.getProduct(a, b) << std::endl;
    IS_TRUE(test1.getProduct(a, b) == (a*b))

    int quotient;
    int remainder;
    test1.getQuotientAndRemainder(a, b, quotient, remainder);

    std::cout << "Quotient: " << quotient << ", Remainder: " << remainder << std::endl;

    std::cout << "Divided value: " << test1.getDividedValue(a, b) << std::endl;
    IS_TRUE(test1.getDividedValue(a, b) == (a*1.0/b))

    std::cout << "Average: " << test1.getAverage(a, b) << std::endl;
    IS_TRUE(test1.getAverage(a, b) == ((a+b)/2))

    std::cout << "Average is " << ((test1.isAverageWithinDesiredMaxValue(a, b) == true) ? "WITHIN" : "OUTSIDE OF") << " max_average_value. [max_average_value=" << test1.get_mMax_average_value() << "]" << std::endl;

    std::cout << "Square root: " << test1.getSquareRootOfProduct(a, b) << std::endl;
    IS_TRUE(test1.getSquareRootOfProduct(a, b) == (sqrt(a*b)))

    std::cout << "Square root is " << ((test1.isSquareRootOfProductWithinDesiredMaxValue(a, b) == true) ? "WITHIN" : "OUTSIDE OF") << " max_square_root_value. [max_square_root_value=" << test1.get_mMax_square_root_value() << "]" << std::endl;

    return 0;
}
