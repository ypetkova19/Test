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
               const char *message)
{
    std::cout << "F:" << filename << " L:" << line << ": " << message << std::endl;
}

Functions::Functions()
{
    mVar1 = 0;
    mVar2 = 0;
    mMax_average_value = 0;
    mMax_square_root_value = 0;
    std::cout << "Default Constructor created" << std::endl;
}

Functions::Functions(int a, int b): mVar1(a), mVar2(b)
{
    mMax_average_value = 0;
    mMax_square_root_value = 0;
    std::cout << "Constructor created. mVar1=" << mVar1 << ", mVar2="<< mVar2 << std::endl;
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

void Functions::set_mMax_square_root_value(int value)
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

unsigned int Functions::getSquareRootOfProduct(int a, int b)
{
    // missing exception for negative values
    int product = Functions::getProduct(a, b);
    if ( product < 0 )
    {
        throw std::invalid_argument("sqrt received negative argument");
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

/* pass by reference */
void Functions::getQuotientAndRemainder(int a, int b, int &quotient, int &remainder)
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
        print_log(FILE, LINE, "Error: cannot divide by zero.");
        return 0.0;
    }

    return (a  * 1.0 / b);
}

#endif
