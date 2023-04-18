/**
 * @file TestClass.hpp
 * @author Yolina Petkova (yolina.petkova@strypes.eu)
 * @brief This file contains function prototypes.
 * @version 0.1
 * @date 2023-04-13
 *
 * @copyright Copyright (c) 2023
 *
 *************************************************************************/
#include <string>

class TestClass
{
    private:
        int mVar1;
        int mVar2;
        int mMax_average_value;
        unsigned int mMax_square_root_value;

    public:
        /**
         * @brief Construct a new Test Class:: Test Class object
         * @par Initialize member variables
         *************************************************************************/
        TestClass();

        /**
         * @brief Construct a new Test Class:: Test Class object
         *
         * @param var1 First value in any mathematical operation
         * @param var2 Second value in any mathematical operation
         * @param max_average_value Max desired average value of above vars
         * @param max_sqrt_value Max desired square root value of the product of above vars
         **************************************************************************/
        TestClass(int var1, int var2, int max_average_value, unsigned int max_sqrt_value);;

        /* Methods */

        /**
         * @brief Tests the mathematical operation function.
         * @par Functions tests with any positive or negative integer value, including chars and decimals
         * Chars are ascii integers and decimals will be truncated
         * @note Operation may overflow
         *
         **************************************************************************/
        void test_getSum();

        /**
         * @brief Tests the good weather mathematical operation function scenarios.
         *
         **************************************************************************/
        void test_valid_getSum();

        /**
         * @brief Tests the bad weather mathematical operation function scenarios.
         *
         **************************************************************************/
        void test_invalid_getSum();

        /**
         * @brief Tests the mathematical operation function.
         * @par Functions tests with any positive or negative integer value, including chars and decimals
         * Chars are ascii integers and decimals will be truncated
         * @note Operation may overflow
         *
         **************************************************************************/
        void test_getAverage();

        /**
         * @brief Tests the good weather mathematical operation function scenarios.
         *
         **************************************************************************/
        void test_valid_getAverage();

        /**
         * @brief Tests the bad weather mathematical operation function scenarios.
         *
         **************************************************************************/
        void test_invalid_getAverage();

        /**
         * @brief Tests whether the mathematical operation results within the desired range.
         * @par Functions tests with any positive or negative integer value, including chars and decimals
         * Chars are ascii integers and decimals will be truncated
         * @note Operation may overflow
         *
         **************************************************************************/
        void test_isAverageWithinDesiredMaxValue();

        /**
         * @brief Tests the mathematical operation function.
         * @par Functions tests with any positive or negative integer value, including chars and decimals
         * Chars are ascii integers and decimals will be truncated
         * @note Operation may overflow
         *
         **************************************************************************/
        void test_getDifference();

        /**
         * @brief Tests the good weather mathematical operation function scenarios.
         *
         **************************************************************************/
        void test_valid_getDifference();

        /**
         * @brief Tests the bad weather mathematical operation function scenarios.
         *
         **************************************************************************/
        void test_invalid_getDifference();

        /**
         * @brief Tests the mathematical operation function.
         * @par Functions tests with any positive or negative integer value, including chars and decimals
         * Chars are ascii integers and decimals will be truncated
         * @note Operation may overflow
         *
         **************************************************************************/
        void test_getProduct();

        /**
         * @brief Tests the good weather mathematical operation function scenarios.
         *
         **************************************************************************/
        void test_valid_getProduct();

        /**
         * @brief Tests the bad weather mathematical operation function scenarios.
         *
         **************************************************************************/
        void test_invalid_getProduct();

        /**
         * @brief Tests the mathematical operation function.
         * @par Functions tests with any positive or negative integer value, including chars and decimals
         * Chars are ascii integers and decimals will be truncated
         * @note Operation may overflow OR may fail when product results in negative value
         *
         **************************************************************************/
        void test_getSquareRootOfProduct();

        /**
         * @brief Tests the good weather mathematical operation function scenarios.
         *
         **************************************************************************/
        void test_valid_getSquareRootOfProduct();

        /**
         * @brief Tests the bad weather mathematical operation function scenarios.
         *
         **************************************************************************/
        void test_invalid_getSquareRootOfProduct();

        /**
         * @brief Tests whether the mathematical operation results within the desired range.
         * @par Functions tests with any positive or negative integer value, including chars and decimals
         * Chars are ascii integers and decimals will be truncated
         * @note Operation may overflow OR may fail when product results in negative value
         *
         **************************************************************************/
        void test_isSquareRootOfProductWithinDesiredMaxValue();

        /**
         * @brief Tests the good weather mathematical operation function scenarios.
         *
         **************************************************************************/
        void test_valid_isSquareRootOfProductWithinDesiredMaxValue();

        /**
         * @brief Tests the bad weather mathematical operation function scenarios.
         *
         **************************************************************************/
        void test_invalid_isSquareRootOfProductWithinDesiredMaxValue();

        /**
         * @brief Tests the mathematical operation function.
         * @par Functions tests with any positive or negative integer value, including chars and decimals
         * Chars are ascii integers and decimals will be truncated
         * @note Operation may overflow
         *
         **************************************************************************/
        void test_getDividedValue();

        /**
         * @brief Tests the good weather mathematical operation function scenarios.
         *
         **************************************************************************/
        void test_valid_getDividedValue();

        /**
         * @brief Tests the bad weather mathematical operation function scenarios.
         *
         **************************************************************************/
        void test_invalid_getDividedValue();

        /**
         * @brief Tests the mathematical operation function.
         * @par Functions tests with any positive or negative integer value, including chars and decimals
         * Chars are ascii integers and decimals will be truncated
         * @note Operation may overflow OR operation will handleexception when dividing by zero
         *
         **************************************************************************/
        void test_calculateQuotientAndRemainder();

        /**
         * @brief Tests the good weather mathematical operation function scenarios.
         *
         **************************************************************************/
        void test_valid_calculateQuotientAndRemainder();

        /**
         * @brief Tests the bad weather mathematical operation function scenarios.
         *
         **************************************************************************/
        void test_invalid_calculateQuotientAndRemainder();
};
