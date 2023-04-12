/**
 * @file Functions.cpp
 * @author Yolina Petkova (yolina.petkova@strypes.eu)
 * @brief This file contains the implementation of mathematical function operations
 * @version 0.1
 * @date 2023-04-11
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
//no source file access //libraries //compiled HPP + CPP files creates: target file
//makefile = hpp + cpp creates a library (eg. cmath)
#include <cmath>
#include <stdexcept>

#include "Functions.hpp"

#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED

///@brief File name macro
#define FILE (__FILE__)
///@brief Line number macro
#define LINE (__LINE__)
///@brief Function name macro
#define FUNC (__func__)

void print_log(const std::string& filename,
               int                line,
               const std::string& function,
               const std::string& message)
{
    std::cout << "F:" << filename << " L:" << line << " fn:" << function << " : " << message << std::endl;
}

Functions::Functions()
{
    mVar1 = 0;
    mVar2 = 0;
    mMax_average_value = 0;
    mMax_square_root_value = 0;
    std::cout << std::endl << "Functions Default Constructor created" << std::endl;
}

Functions::Functions(int var1, int var2, int max_average_value, unsigned int max_sqrt_value): mVar1(var1), mVar2(var2), mMax_average_value(max_average_value), mMax_square_root_value(max_sqrt_value)
{
    std::cout << "Functions Constructor created. mVar1=" << mVar1 << ", mVar2="<< mVar2 << ", mMax_average_value="<< mMax_average_value << ", mMax_square_root_value="<< mMax_square_root_value << std::endl << std::endl;
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

int Functions::getSum(int var1, int var2)
{
    int sum = var1 + var2;

    if (((var1 > 0) && (var2 > 0) && (sum < 0)) ||
        ((var1 < 0) && (var2 < 0) && (sum > 0)))
    {
        throw std::overflow_error("Stack overflow!");
    }

    return sum;
}

int Functions::getAverage(int var1, int var2)
{
    int average = ((var1 + var2)/2);

    if (((var1 > 0) && (var2 > 0) && (average < 0)) ||
        ((var1 < 0) && (var2 < 0) && (average > 0)))
    {
        throw std::overflow_error("Stack overflow!");
    }

    return average;
}

bool Functions::isAverageWithinDesiredMaxValue(int var1, int var2)
{
    if (Functions::getAverage(var1, var2) > Functions::get_mMax_average_value())
    {
        return false;
    }
    return true;
}

int Functions::getDifference(int var1, int var2)
{
    int diff = var1 - var2;

    if (((var1 > 0) && (var2 < 0) && (diff < 0)) ||
        ((var1 < 0) && (var2 > 0) && (diff > 0)))
    {
        throw std::overflow_error("Stack overflow!");
    }

    return diff;
}

int Functions::getProduct(int var1, int var2)
{
    int product = var1 * var2;

    if (var1 != 0 && (var2 != (product / var1)))
    {
        throw std::overflow_error("Stack overflow!"); //add exception documentation to README.md
        //1.auto-generate with doxygen
        //2.or manual documentation
        //static code analysis tool for C++ code - command line tool
    }

    return product;
}

double Functions::getSquareRootOfProduct(int var1, int var2)
{
    int product = Functions::getProduct(var1, var2);

    if ( product < 0 )
    {
        throw std::invalid_argument("Negative product!");
        //gdb print stack
    }

    return sqrt(product);
}

bool Functions::isSquareRootOfProductWithinDesiredMaxValue(int var1, int var2)
{
    double square_root = Functions::getSquareRootOfProduct(var1, var2);

    if (square_root > Functions::get_mMax_square_root_value())
    {
        return false;
    }
    return true;
}

int Functions::getQuotient(const int &var1, const int &var2)
{
    if (var2 == 0)
    {
        throw std::invalid_argument("Second argument is zero.");
    }

    /* catch 2's complement overflow */
    if ((var1 == INT_MIN) && (var2 == -1))
    {
        throw std::overflow_error("Stack overflow!");
    }

    return (var1 / var2);
}

int Functions::getRemainder(const int &var1, const int &var2)
{
    return (var1 % var2);
}

double Functions::getDividedValue(int var1, int var2)
{
    try
    {
        if (var2 == 0)
        {
            throw std::invalid_argument("Second argument is zero.");
        }
    }
    catch (const std::invalid_argument& e)
    {
        return 0.0;
    }

    double divided_value = var1 * 1.0 / var2;

    /* catch 2's complement overflow */
    if ((var1 == INT_MIN) && (var2 == -1))
    {
        throw std::overflow_error("Stack overflow!");
    }

    return divided_value;
}

#endif
