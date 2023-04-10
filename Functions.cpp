#include <iostream>
#include <cmath>
#include <stdexcept>

#include "Functions.hpp"

#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED

#define FILE (__FILE__)
#define LINE (__LINE__)
#define FUNCTION (__func__)

void print_log(std::string filename,
               int         line,
               std::string message)
{
    std::cout << "F:" << filename << " L:" << line << ": " << message << std::endl;
}

Functions::Functions()
{
    mVar1 = 0; /* unused */
    mVar2 = 0; /* unused */
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

int Functions::get_mVar1()
{
    return mVar1;
}

int Functions::get_mVar2()
{
    return mVar2;
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
    int sum = a + b;

    if (((a > 0) && (b > 0) && (sum < 0)) ||
        ((a < 0) && (b < 0) && (sum > 0)))
    {
        throw std::overflow_error("Stack overflow!");
    }

    return sum;
}

int Functions::getAverage(int a, int b)
{
    int average = ((a + b)/2);

    if (((a > 0) && (b > 0) && (average < 0)) ||
        ((a < 0) && (b < 0) && (average > 0)))
    {
        throw std::overflow_error("Stack overflow!");
    }

    return average;
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
    int diff = a - b;

    if (((a > 0) && (b < 0) && (diff < 0)) ||
        ((a < 0) && (b > 0) && (diff > 0)))
    {
        throw std::overflow_error("Stack overflow!");
    }

    return diff;
}

int Functions::getProduct(int a, int b)
{
    int product = a * b;

    if (a != 0 && (b != (product / a)))
    {
        throw std::overflow_error("Stack overflow!");
    }

    return product;
}

double Functions::getSquareRootOfProduct(int a, int b)
{
    int product = 0;

    // try
    // {
        product = Functions::getProduct(a, b);
    // }
    // catch (const std::overflow_error& e)
    // {
    //     // throw new std::Exception("Exception.", e)
    //     std::cout << "F:" << FILE << " L:" << LINE << " fn:" << FUNCTION << " : Expected: catch 'overflow_error' [mVar1=" << a << ", mVar2=" << b << "]. Actual: " << e.what() <<  " .....PASS" << std::endl;
    // }

    if ( product < 0 )
    {
        throw std::invalid_argument("getSquareRootOfProduct received negative argument");
    }

    return sqrt(product);
}

bool Functions::isSquareRootOfProductWithinDesiredMaxValue(int a, int b)
{
    double square_root = Functions::getSquareRootOfProduct(a, b);

    // if (square_root < 0)
    // {
    //     throw std::invalid_argument("getSquareRootOfProduct returned invalid argument");
    // }

    if (square_root > Functions::get_mMax_square_root_value())
    {
        return false;
    }
    return true;
}

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

#if 0 //UNUSED FN AS QUOTIENT AND REMAINDER ARE SPLIT UP NOW
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
