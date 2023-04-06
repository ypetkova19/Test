#include <iostream>
#include <cmath>
#include <cassert>  
#include <string>  
#include <stdexcept>

// using namespace std; //use std::std::cout

#define FILE (__FILE__)
#define LINE (__LINE__)

#define IS_TRUE(x) { if (!(x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }

#if 0 //CALL WITH ADI
//QN does this mean that the function return code should be boolean?
//when having a func it retuns: error, success, or bad scenario (lower than expected but perhaps within accepted range)
int func(int fill_var)
{
    //error
    //or SOME value
    //
}
//UT and behavioural tests
//behaviour = UT + more -> more than one function.. like IT
//UT = tests only one function
// two scenarios: bad and good
//good weather scenario = success test case with correct result
//bad weather scenario = fn returns error according to the inputs, but the exception IS handled.. and that's ok. the fn corectly returns/handles the exception
//example: error with input params OR throw unacceptable_yolina_error 

//for assertions, your fn must always return true/false
//checking input arguments + checking all errors within function given those input parameters
bool func_buy_bread(int money)
{
    try 
    {
        if ((money == 0) || (money < 0) || (money < cost_of_bread))
            throw money
    }
    catch (unacceptable_debt_error)
    {
        //warning log + return bad weather scenario
        return false;
    }
    //and other aceptable debt cases...
    //example when money = -5, function returns throws unacceptable_negative_money

    //create a new class of error
    return true;
}

//Test Driven Development (TDD)
//write test cases FIRST
//then write the function and as you write the fn, ALL cases must be satisfied

#endif

// #define LOG_LENGTH (300)
const int LOG_LENGTH = 300;

void print_log(std::string filename,
               int         line,
               const char *message)
{
    // printf("F:%s L:%d : %s\n", filename, line, message);
    std::cout << "F:" << filename << " L:" << line << ": " << message << std::endl;
}
typedef struct
{
    /* data */
    int var;
} my_type_t;

my_type_t yolina;

// yolina.var = 9;

//#include class_function_header_file.h
class TestClass
{
    private:
        int var1;
        int var2;
        // double var3;
        // double var4;
        int max_average_value;
        int max_square_root_value;

    public:
    //get and set functions are public

        TestClass()
        {
            std::cout << "Default Constructor for TestClass" << std::endl;
        }
        TestClass(int a, int b): var1(a), var2(b)
        {
            max_average_value = 10;
            max_square_root_value = 7;
            std::cout << "Parameterized Constructor values-" << a << " "<< b << std::endl;
        }
        // set
        // get 
        // TestClass(int a, int b)
        // {
        //     var1 = a;
        //     var2 = b;
        //     max_average_value = 10;
        //     max_square_root_value = 7;
        // }

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

        int getMaxAverageValue()
        {
            return max_average_value;
        }

        bool isAverageWithinDesiredMaxValue(int a, int b)
        {
            if (getAverage(a, b) > getMaxAverageValue())
            {
                // printf("ERROR: Average outside of max_average_value. [max_average_value=%d]", max_average_value);
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

        int getMaxSquareRootValue()
        {
            return max_square_root_value;
        }

        bool isSquareRootOfProductWithinDesiredMaxValue(int a, int b)
        {
            if (getSquareRoot(a, b) > getMaxSquareRootValue())
            {
                return false;
            }
            return true;
        }

#if 0 //pass by pointer
        void getQuotientAndRemainder(int *quotient, int *remainder)
        {
            if ((quotient == NULL) && (remainder == NULL))
            {
                print_log(FILE, LINE, "NULL ptr");
            }

            if (var2 == 0)
            {
                print_log(FILE, LINE, "Error: cannot divide by zero.");
            }

            *quotient = var1 / var2;
            *remainder = var1 % var2;
        } 
#endif        

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
    // calling the function
    //tbd();

    // std::cout << "F:%s L:%d Test print\n" << FILE << LINE;
    // printf("F:%s L:%d Test print\n", FILE, LINE);
    print_log(FILE, LINE, "Test print");

    // int a = 8;
    // int b = 5;

    int a;
    int b;

    std::cout << "Enter first integer value: ";
    std::cin >> a;
    std::cout << "Enter second integer value: ";
    std::cin >> b;

    // printf("Working with integers: %d and %d\n", a, b);
    std::cout << "Working with integers: " << a << "and " << b << std::endl;

    //Add error checking to user input... as we cannot divide by zero. MOVED CHECK ELSEWHERE.
    // assert(b != 0);

    /* create object of type TestClass */
    TestClass test1(a, b);
    // printf("Sum: %d\n", test1.getSum());
    std::cout << "Sum: " << test1.getSum(a, b) << std::endl;

    // printf("Difference: %d\n", test1.getDifference());
    std::cout << "Difference: " << test1.getDifference(a, b) << std::endl;

    // printf("Product: %d\n", test1.getProduct());
    std::cout << "Product: " << test1.getProduct(a, b) << std::endl;

    int quotient;
    int remainder;
    // test1.getQuotientAndRemainder(&quotient, &remainder);
    test1.getQuotientAndRemainder(a, b, quotient, remainder);

    // char message[LOG_LENGTH] = {0};
    // snprintf(message, LOG_LENGTH, "quotient=%d, remainder=%d", quotient, remainder);
    // print_log(FILE, LINE, message);

    // printf("Quotient=%d, Remainder=%d\n", quotient, remainder);
    std::cout << "Quotient: " << quotient << ", Remainder: " << remainder << std::endl;

    // printf("Divided value: %f\n", test1.getDividedValue());
    std::cout << "Divided value: " << test1.getDividedValue(a, b) << std::endl;

    // printf("Average: %d\n", test1.getAverage());
    std::cout << "Average: " << test1.getAverage(a, b) << std::endl;

    // printf("Average is %s max_average_value. [max_average_value=%d]\n", 
            // (test1.isAverageWithinDesiredMaxValue() == true) ? "WITHIN" : "OUTSIDE OF",
            // test1.getMaxAverageValue());
    std::cout << "Average is " << ((test1.isAverageWithinDesiredMaxValue(a, b) == true) ? "WITHIN" : "OUTSIDE OF") << " max_average_value. [max_average_value=" << test1.getMaxAverageValue() << "]" << std::endl;

    // printf("Square root: %d\n", test1.getSquareRoot());
    std::cout << "Square root: " << test1.getSquareRoot(a, b) << std::endl;

    // printf("Square root is %s max_square_root_value. [max_square_root_value=%d]\n", 
    //         (test1.isSquareRootOfProductWithinDesiredMaxValue() == true) ? "WITHIN" : "OUTSIDE OF",
    //         test1.getMaxSquareRootValue());
    std::cout << "Square root is " << ((test1.isSquareRootOfProductWithinDesiredMaxValue(a, b) == true) ? "WITHIN" : "OUTSIDE OF") << " max_square_root_value. [max_square_root_value=" << test1.getMaxSquareRootValue() << "]" << std::endl;


    

    // Test for function1()
    // You would need to write these even when using a framework
    // void test_function1()
    // {
    //     IS_TRUE(!function1(0));
    //     IS_TRUE(!function1(5));
    //     IS_TRUE(function1(10));
    // }


#if 0 // FOR FUTURE. IGNORE HERE.
    double x = 8.0;
    double y = 5.5;

    TestClass test2(x, y);
    printf("%f\n", test2.getSum(x, y));
#endif

    return 0;
}
