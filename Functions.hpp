/************************************************
 * File       : Functions.hpp
 * Description: This file contains function
 *              prototypes.
 ************************************************/
#include <string>

const int LOG_LENGTH = 300;

void print_log(std::string filename,
               int         line,
               std::string message);


class Functions
{
    private:
        int mVar1;
        int mVar2;
        int mMax_average_value;
        unsigned int mMax_square_root_value;

    public:
        Functions();
        Functions(int a, int b, int c, unsigned int d);

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
        int getQuotient(int &a, int &b);
        int getRemainder(int &a, int &b);
        // bool calculateQuotientAndRemainder(int a, int b, int &quotient, int &remainder);
        double getDividedValue(int a, int b);
};
