#include <iostream>
#include <cmath>
#include <cassert>  
#include <string>  
#include <stdexcept>

#define FILE (__FILE__)
#define LINE (__LINE__)

#define IS_TRUE(x) { if (!(x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }

const int LOG_LENGTH = 300;

void print_log(std::string filename,
               int         line,
               const char *message)
{
    std::cout << "F:" << filename << " L:" << line << ": " << message << std::endl;
}

//#include class_function_header_file.h
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

        void set_mVar1(int value)
        {
            mVar1 = value;
        }
        void set_mVar2(int value)
        {
            mVar2 = value;
        }
        void set_mMax_average_value(int value)
        {
            mMax_average_value = value;
        }
        void set_mMax_square_root_value(int value)
        {
            mMax_square_root_value = value;
        }

        int get_mMax_average_value()
        {
            return mMax_average_value;
        }
        int get_mMax_square_root_value()
        {
            return mMax_square_root_value;
        }

        /* Function methods */

        int getSum(int a, int b)
        {
            return (a + b);
        }
        //UT
        // IS_TRUE(getSum(15, 17) == 32)
        // IS_TRUE(getSum(-5, 5))

        int getAverage(int a, int b)
        {
            return ((a + b)/2);
        }

        bool isAverageWithinDesiredMaxValue(int a, int b)
        {
            if (getAverage(a, b) > get_mMax_average_value())
            {
                return false;
            }
            return true;
        }

        int getDifference(int a, int b)
        {
            return (a - b);
        }

        int getProduct(int a, int b)
        {
            return (a * b);
        }

        unsigned int getSquareRoot(int a, int b)
        {
            // missing exception for negative values
            int product = getProduct(a, b);
            if ( product < 0 )
            {
                throw std::invalid_argument("sqrt received negative argument");
            }
            return sqrt(product);
        }

        bool isSquareRootOfProductWithinDesiredMaxValue(int a, int b)
        {
            if (getSquareRoot(a, b) > get_mMax_square_root_value())
            {
                return false;
            }
            return true;
        }

        /* pass by reference */
        void getQuotientAndRemainder(int a, int b, int &quotient, int &remainder)
        {
            try 
            {
                if (b == 0)
                {
                    throw std::invalid_argument("Second argument is zero.");
                }
            }
            catch (const std::invalid_argument& e)
            {
                quotient = 0;
                remainder = 0;
                print_log(FILE, LINE, "Error: cannot divide by zero.");
                return;
            }

            quotient = a / b;
            remainder = a % b;
        } 

        double getDividedValue(int a, int b)
        {
            try 
            {
                if (b == 0)
                {
                    throw std::invalid_argument("Second argument is zero.");
                }
            }
            catch (const std::invalid_argument& e)
            {
                print_log(FILE, LINE, "Error: cannot divide by zero.");
                return 0.0;
            }

            return (a  * 1.0 / b);
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

    std::cout << "Working with integers: " << a << "and " << b << std::endl;

    /* create object of type TestClass */
    TestClass test1(a, b);
    std::cout << "Sum: " << test1.getSum(a, b) << std::endl;

    std::cout << "Difference: " << test1.getDifference(a, b) << std::endl;

    std::cout << "Product: " << test1.getProduct(a, b) << std::endl;

    int quotient;
    int remainder;
    test1.getQuotientAndRemainder(a, b, quotient, remainder);

    std::cout << "Quotient: " << quotient << ", Remainder: " << remainder << std::endl;

    std::cout << "Divided value: " << test1.getDividedValue(a, b) << std::endl;

    std::cout << "Average: " << test1.getAverage(a, b) << std::endl;

    std::cout << "Average is " << ((test1.isAverageWithinDesiredMaxValue(a, b) == true) ? "WITHIN" : "OUTSIDE OF") << " max_average_value. [max_average_value=" << test1.get_mMax_average_value() << "]" << std::endl;

    std::cout << "Square root: " << test1.getSquareRoot(a, b) << std::endl;

    std::cout << "Square root is " << ((test1.isSquareRootOfProductWithinDesiredMaxValue(a, b) == true) ? "WITHIN" : "OUTSIDE OF") << " max_square_root_value. [max_square_root_value=" << test1.get_mMax_square_root_value() << "]" << std::endl;

    return 0;
}
