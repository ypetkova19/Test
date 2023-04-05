#include <iostream>
#include <cmath>
#include <cassert>  

using namespace std; //use std::cout

#define FILE (__FILE__)
#define LINE (__LINE__)

// #define LOG_LENGTH (300)
const int LOG_LENGTH = 300;

void print_log(const char *filename,
               int         line,
               const char *message)
{
    printf("F:%s L:%d : %s\n", filename, line, message);
}

class TestClass
{
    private:
        int var1;
        int var2;
        double var3;
        double var4;
        int max_average_value;
        int max_square_root_value;

    public:
    //get and set functions are public

        TestClass(int a, int b)
        {
            var1 = a;
            var2 = b;
            max_average_value = 10;
            max_square_root_value = 7;
        }

        //do not create constructors with same number of parameters, ideally different number of parameters
        TestClass(double a, double b)
        {
            var3 = a;
            var4 = b;
        }

        // double getSum(double var1, double var2)
        // {
        //     return (var3 + var4);
        // }

        int getSum(void)
        {
            return (var1 + var2);
        }

        int getDifference(void)
        {
            return (var1 - var2);
        }

        int getProduct(void)
        {
            return (var1 * var2);
        }

        int getSquareRoot(void)
        {
            return sqrt(getProduct());
        }

        bool isSquareRootOfProductWithinDesiredMaxValue(void)
        {
            if (getSquareRoot() > max_square_root_value)
            {
                return false;
            }
            return true;
        }

        // void getQuotientAndRemainder(int *quotient, int *remainer)
        void getQuotientAndRemainder(int &quotient, int &remainer)
        {
            // if ((quotient == NULL) && (remainer == NULL))
            // {
            //     print_log(FILE, LINE, "NULL ptr");
            // }

            if (var2 == 0)
            {
                print_log(FILE, LINE, "Error: cannot divide by zero.");
            }

            // *quotient = var1 / var2;
            // *remainer = var1 % var2;

            quotient = var1 / var2;
            remainer = var1 % var2;
        } 

        int getAverage(void)
        {
            return ((var1 + var2)/2);
        }

        bool isAverageWithinDesiredMaxValue(void) //remove void
        {
            if (getAverage() > max_average_value)
            {
                // printf("ERROR: Average outside of max_average_value. [max_average_value=%d]", max_average_value);
                return false;
            }
            return true;
        }

        int getMaxRangeValue(void)
        {
            return max_average_value;
        }

        int getMaxSquareRootValue(void)
        {
            return max_square_root_value;
        }
};

int main() 
{
    // calling the function
    //tbd();

    // cout << "F:%s L:%d Test print\n" << FILE << LINE;
    // printf("F:%s L:%d Test print\n", FILE, LINE);
    print_log(FILE, LINE, "Test print");

    // int a = 8;
    // int b = 5;

    int a;
    int b;

    cout << "Enter first integer value: ";
    cin >> a;
    cout << "Enter second integer value: ";
    cin >> b;

    printf("Working with integers: %d and %d\n", a, b);

    //Add error checking to user input... as we cannot divide by zero.
    assert(b != 0);

    TestClass test1(a, b);
    printf("Sum: %d\n", test1.getSum());

    printf("Difference: %d\n", test1.getDifference());

    printf("Product: %d\n", test1.getProduct());

    int quotient;
    int remainder;
    // test1.getQuotientAndRemainder(&quotient, &remainder);
    test1.getQuotientAndRemainder(quotient, remainder);

    char message[LOG_LENGTH] = {0};
    snprintf(message, LOG_LENGTH, "quotient=%d, remainder=%d", quotient, remainder);
    print_log(FILE, LINE, message);

    printf("Average: %d\n", test1.getAverage());

    printf("Average is %s max_average_value. [max_average_value=%d]\n", 
            (test1.isAverageWithinDesiredMaxValue() == true) ? "WITHIN" : "OUTSIDE OF",
            test1.getMaxRangeValue());

    printf("Square root: %d\n", test1.getSquareRoot());

    printf("Square root is %s max_square_root_value. [max_square_root_value=%d]\n", 
            (test1.isSquareRootOfProductWithinDesiredMaxValue() == true) ? "WITHIN" : "OUTSIDE OF",
            test1.getMaxSquareRootValue());

#if 0
    double x = 8.0;
    double y = 5.5;

    TestClass test2(x, y);
    printf("%f\n", test2.getSum(x, y));
#endif

    return 0;
}
