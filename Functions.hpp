/************************************************
 * File       : Functions.h
 * Description: This file contains function 
 *              prototypes.
 ************************************************/
#include <string>  

const int LOG_LENGTH = 300;

void print_log(std::string filename,
               int         line,
               const char *message);


class Functions
{
    private:
        int mVar1;
        int mVar2;
        int mMax_average_value;
        unsigned int mMax_square_root_value;

    public:
        Functions();
        Functions(int a, int b);

        void set_mVar1(int value);
        void set_mVar2(int value);
        void set_mMax_average_value(int value);
        void set_mMax_square_root_value(int value);

        int get_mMax_average_value();
        int get_mMax_square_root_value();

        /* Function methods */

        int getSum(int a, int b);
        int getAverage(int a, int b);
        bool isAverageWithinDesiredMaxValue(int a, int b);
        int getDifference(int a, int b);
        int getProduct(int a, int b);
        unsigned int getSquareRoot(int a, int b);
        bool isSquareRootOfProductWithinDesiredMaxValue(int a, int b);
        void getQuotientAndRemainder(int a, int b, int &quotient, int &remainder);
        double getDividedValue(int a, int b);
};
