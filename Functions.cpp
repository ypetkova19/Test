#include <iostream>
#include <cmath>
#include "Functions.hpp"
#include <stdexcept>

#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED

#define FILE (__FILE__)
#define LINE (__LINE__)

void print_log(std::string filename,
               int         line,
               std::string message)
{
    std::cout << "F:" << filename << " L:" << line << ": " << message << std::endl;
}

Functions::Functions()
{
    mVar1 = 0;
    mVar2 = 0;
    mMax_average_value = 0;
    mMax_square_root_value = 0;
    std::cout << std::endl << "Functions Default Constructor created" << std::endl;
}

Functions::Functions(int a, int b, int c, unsigned int d): mVar1(a), mVar2(b), mMax_average_value(c), mMax_square_root_value(d)
{
    std::cout << std::endl << "Functions Constructor created. mVar1=" << mVar1 << ", mVar2="<< mVar2 << std::endl;
}

void Functions::set_mVar1(int value)
{
    mVar1 = value;
}

void Functions::set_mVar2(int value)
{
    mVar2 = value;
}

void Functions::set_mMax_average_value(int value)
{
    mMax_average_value = value;
}

void Functions::set_mMax_square_root_value(unsigned int value)
{
    mMax_square_root_value = value;
}

int Functions::get_mMax_average_value()
{
    return mMax_average_value;
}

int Functions::get_mMax_square_root_value()
{
    return mMax_square_root_value;
}

/* Function methods */

int Functions::getSum(int a, int b)
{
    return (a + b);
}

int Functions::getAverage(int a, int b)
{
    return ((a + b)/2);
}

bool Functions::isAverageWithinDesiredMaxValue(int a, int b)
{
    if (Functions::getAverage(a, b) > Functions::get_mMax_average_value())
    {
        return false;
    }
    return true;
}

int Functions::getDifference(int a, int b)
{
    return (a - b);
}

int Functions::getProduct(int a, int b)
{
    return (a * b);
}

double Functions::getSquareRootOfProduct(int a, int b)
{
    // missing exception for negative values
    int product = Functions::getProduct(a, b);
    try
    {
        if ( product < 0 )
        {
            throw std::invalid_argument("getSquareRootOfProduct received negative argument");
        }
    }
    catch (const std::invalid_argument& e)
    {
        // print_log(FILE, LINE, "Error: cannot take square root of negative value.");
        std::cout << "ERROR: F:" << FILE << " L:" << LINE << ": " << "Error: cannot take square root of negative value. [mVar1=" << a << ", mVar2=" << b << ", product=" << product << "]" << std::endl;
        return -1;
    }
    return sqrt(product);
}

bool Functions::isSquareRootOfProductWithinDesiredMaxValue(int a, int b)
{
    if (Functions::getSquareRootOfProduct(a, b) > Functions::get_mMax_square_root_value())
    {
        return false;
    }
    return true;
}

#if 0
/* pass by reference */
//tuples in c++, 2 in 1
//return tuple

typedef struct
{
    int var;
} yolina_t;

C
yolina_t *var = calloc(1, sizeof(*var));
//equivalent to:
int* ptr = new int;

free(var)

C++
yolina_t var = new() //
delete(var) //from heap

#define DDXA_CREATE(x)
{
    x = calloc(1, sizeof(*x));
}
#define DDXA_DELETE(x)
{
    free(x);
}



int array[3];
array[0] = 0x100
array[1] = 0x104
array[2] = 0x108

get(int array[])
{

}
#endif

//cost reference
int Functions::getQuotient(int &a, int &b)
{
    if (b == 0)
    {
        throw std::invalid_argument("Second argument is zero.");
        return false;
    }
    return (a / b);
}

int Functions::getRemainder(int &a, int &b)
{
    return (a % b);
}

#if 0
bool Functions::calculateQuotientAndRemainder(int a, int b, int &quotient, int &remainder)
{
    quotient = 0;
    remainder = 0;

    if (b == 0)
    {
        throw std::invalid_argument("Second argument is zero.");
        return false;
    }

    quotient = a / b;
    remainder = a % b;
    return true;
}
#endif

double Functions::getDividedValue(int a, int b)
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
        // print_log(FILE, LINE, "Error: cannot divide by zero.");
        std::cout << "ERROR: F:" << FILE << " L:" << LINE << ": " << "Error: cannot divide by zero. [mVar1=" << a << "mVar2=" << b << "]" << std::endl;
        return 0.0;
    }

    return (a  * 1.0 / b);
}

#endif
