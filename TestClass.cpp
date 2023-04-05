#include <iostream>
using namespace std;

#define FILE (__FILE__)
#define LINE (__LINE__)

#define LOG_LENGTH (300)

void print_log(const char* filename,
               int    line,
               const char *message)
{
    printf("F:%s L:%d : %s\n", filename, line, message);
}

class TestClass
{
    public:
        int var1;
        int var2;
        double var3;
        double var4;
        int range = 10;

        TestClass(int a, int b)
        {
            var1 = a;
            var2 = b;
        }

        TestClass(double a, double b)
        {
            var3 = a;
            var4 = b;
        }

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

        // double getSum(double var1, double var2)
        // {
        //     return (var3 + var4);
        // }

        void getQuotientAndRemainder(int *quotient, int *remainer)
        {
            if ((quotient == NULL) && (remainer == NULL))
            {
                print_log(FILE, LINE, "NULL ptr");
            }

            if (var2 == 0)
            {
                print_log(FILE, LINE, "Error: cannot divide by zero.");
            }

            *quotient = var1 / var2;
            *remainer = var1 % var2;
        } 

        int getAverage(void)
        {
            return ((var1 + var2)/2);
        }

        bool isAverageWithinDesiredRange(void)
        {
            if (getAverage() > range)
            {
                // printf("ERROR: Average outside of range. [range=%d]", range);
                return false;
            }
            return true;
        }

        int getRangeValue(void)
        {
            return range;
        }
};



int main() {

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

    //Add error checking...

    TestClass test1(a, b);
    printf("Sum: %d\n", test1.getSum());

    printf("Difference: %d\n", test1.getDifference());

    printf("Product: %d\n", test1.getProduct());

#if 0
    double x = 8.0;
    double y = 5.5;

    TestClass test2(x, y);
    printf("%f\n", test2.getSum(x, y));
#endif

    int quotient;
    int remainder;
    test1.getQuotientAndRemainder(&quotient, &remainder);

    //QN: HOW DO I MAKE A FUNCTION WITH VARIABLE NUMBER OF PARAMS? CAN THAT BE DONE? OR IS MACRO THE BEST WAY TO GO HERE?
    char message[LOG_LENGTH] = {0};
    snprintf(message, LOG_LENGTH, "quotient=%d, remainder=%d", quotient, remainder);
    print_log(FILE, LINE, message);

    printf("Average: %d\n", test1.getAverage());

    

    // bool is_within_range = test1.isAverageWithinDesiredRange();

    // if (is_within_range == true)
    // {
    // }

    printf("Average is %s range. [range=%d]\n", 
            (test1.isAverageWithinDesiredRange() == true) ? "WITHIN" : "OUTSIDE OF",
            test1.getRangeValue());
    

    return 0;
}
