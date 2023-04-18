/**
 * @file Functions.hpp
 * @author Yolina Petkova (yolina.petkova@strypes.eu)
 * @brief This file contains function prototypes.
 * @version 0.1
 * @date 2023-04-13
 *
 * @copyright Copyright (c) 2023
 *
 *************************************************************************/
#include <string>

/// @brief Log length max
const int LOG_LENGTH = 300;

/**
 * @brief Prints the formatted message log to the console
 *
 * @param filename File name string
 * @param line Line number
 * @param function Function name string
 * @param message Formatted string message to be printed
 *************************************************************************/
void print_log(const std::string& filename,
               int                line,
               const std::string& function,
               const std::string& message);


class Functions
{
    private:
        int mVar1; /* unused */
        int mVar2; /* unused */
        int mMax_average_value; ///max average value allowed
        unsigned int mMax_square_root_value; ///max square root value allowed

    public:

        /**
         * @brief Construct a new Functions:: Functions object
         * @par Initialize member variables
         *************************************************************************/
        Functions();

        /**
         * @brief Construct a new Functions:: Functions object
         *
         * @param var1 First value in any mathematical operation
         * @param var2 Second value in any mathematical operation
         * @param max_average_value Max desired average value of above vars
         * @param max_sqrt_value Max desired square root value of the product of above vars
         **************************************************************************/
        Functions(int var1, int var2, int max_average_value, unsigned int max_sqrt_value);

        /**
         * @brief Sets param value
         *
         * @param value of mVar1
         **************************************************************************/
        void set_mVar1(int value);

        /**
         * @brief Sets param value
         *
         * @param value of mVar2
         **************************************************************************/
        void set_mVar2(int value);

        /**
         * @brief Sets param value
         *
         * @param value of mMax_average_value
         **************************************************************************/
        void set_mMax_average_value(int value);

        /**
         * @brief Sets param value
         *
         * @param value of mMax_square_root_value
         **************************************************************************/
        void set_mMax_square_root_value(unsigned int value);

        /**
         * @brief Get param value
         *
         * @return int value of mVar1
         **************************************************************************/
        int get_mVar1();

        /**
         * @brief Get param value
         *
         * @return int value of mVar2
         **************************************************************************/
        int get_mVar2();

        /**
         * @brief Get param value
         *
         * @return int value of mMax_average_value
         **************************************************************************/
        int get_mMax_average_value();

        /**
         * @brief Get param value
         *
         * @return int value of mMax_square_root_value
         **************************************************************************/
        int get_mMax_square_root_value();

        /* Function methods */

        /**
         * @brief Get sum of input values
         *
         * @param var1 First value
         * @param var2 Second value
         * @return int Sum value of provided inputs
         **************************************************************************/
        int getSum(int a, int b);

        /**
         * @brief Get average of input values
         *
         * @param var1 First value
         * @param var2 Second value
         * @return int Average valueof provided inputs
         **************************************************************************/
        int getAverage(int a, int b);

        /**
         * @brief Get average of input values
         *
         * @param var1 First value
         * @param var2 Second value
         * @return int Average value of provided inputs
         **************************************************************************/
        bool isAverageWithinDesiredMaxValue(int a, int b);

        /**
         * @brief Get difference of input values
         *
         * @param var1 First value
         * @param var2 Second value
         * @return int difference value of provided inputs
         **************************************************************************/
        int getDifference(int a, int b);

        /**
         * @brief Get product of input variables
         *
         * @param var1 First value
         * @param var2 Second value
         * @return int
         *************************************************************************/
        int getProduct(int a, int b);

        /**
         * @brief Get square root of the product of input variables
         *
         * @param var1 First value
         * @param var2 Second value
         * @return double square root decimal value
         *************************************************************************/
        double getSquareRootOfProduct(int a, int b);

        /**
         * @brief Returns flag indicating whether calculated sqrt value for
         * input variables is within desired max range.
         *
         * @param var1 First value
         * @param var2 Second value
         * @return true
         * @return false
         *************************************************************************/
        bool isSquareRootOfProductWithinDesiredMaxValue(int a, int b);

        /**
         * @brief Get quotient of input variables
         *
         * @param var1 Divident (number to divide)
         * @param var2 Divisor (number dividing by)
         * @return int Quotient value of division operation
         *************************************************************************/
        int getQuotient(const int &a, const int &b);

        /**
         * @brief Get remainder of input variables
         *
         * @param var1 Divident (number to divide)
         * @param var2 Divisor (number dividing by)
         * @return int Remainder (ie. modulus) value of division operation
         *************************************************************************/
        int getRemainder(const int &a, const int &b);

        /**
         * @brief Get result from the division operation of the input variables
         *
         * @param var1 Divident (number to divide)
         * @param var2 Divisor (number dividing by)
         * @return double Resulting value
         *************************************************************************/
        double getDividedValue(int a, int b);
};
