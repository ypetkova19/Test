/************************************************
 * File       : Functions.hpp
 * Description: This file contains function
 *              prototypes.
 ************************************************/
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
 */
void print_log(const std::string& filename,
               int                line,
               const std::string& function,
               const std::string& message);


class Functions
{
    private:
        int mVar1;
        int mVar2;
        int mMax_average_value;
        unsigned int mMax_square_root_value;

    public:
        Functions();
        Functions(int var1, int var2, int max_average_value, unsigned int max_sqrt_value);

        void set_mVar1(int value);
        void set_mVar2(int value);
        void set_mMax_average_value(int value);
        void set_mMax_square_root_value(unsigned int value);

        int get_mVar1();
        int get_mVar2();
        int get_mMax_average_value();
        int get_mMax_square_root_value();

        /* Function methods */

        int getSum(int a, int b);
        int getAverage(int a, int b);
        bool isAverageWithinDesiredMaxValue(int a, int b);
        int getDifference(int a, int b);
        int getProduct(int a, int b);
        double getSquareRootOfProduct(int a, int b);
        bool isSquareRootOfProductWithinDesiredMaxValue(int a, int b);
        int getQuotient(const int &a, const int &b);
        int getRemainder(const int &a, const int &b);
        double getDividedValue(int a, int b);
};
