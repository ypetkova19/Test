#include <iostream>
using namespace std;

#define FILE (__FILE__)
#define LINE (__LINE__)

#define LOG_LENGTH (300)

void print_log(const char* filename,
               int    line,
               const char *message)
{
    printf("F:%s L:%d : %s\n", filename, line, message);
}

class TestClass
{
    public:
        int var1;
        int var2;
        double var3;
        double var4;

        TestClass(int a, int b)
        {
            var1 = a;
            var2 = b;
        }

        TestClass(double a, double b)
        {
            var3 = a;
            var4 = b;
        }

        int getSum(void)
        {
            return (var1 + var2);
        }

        double getSum(double var1, double var2)
        {
            return (var3 + var4);
        }

        void getQuotientAndRemainer(int *quotient, int *remainer)
        {
            if ((quotient == NULL) && (remainer == NULL))
            {
                print_log(FILE, LINE, "NULL ptr");
            }
            *quotient = var1 / var2;
            *remainer = var1 % var2;
        }

        // int sum;
        // int product;
        // int difference;
        // int quotient;
        // int remainder;
        // double 
};



int main() {

    // calling the function
    //tbd();

    // cout << "F:%s L:%d Test print\n" << FILE << LINE;
    // printf("F:%s L:%d Test print\n", FILE, LINE);
    print_log(FILE, LINE, "Test print");

    int a = 8;
    int b = 5;

    TestClass test1(a, b);
    printf("%d\n", test1.getSum());

    double x = 8.0;
    double y = 5.5;

    TestClass test2(x, y);
    printf("%f\n", test2.getSum(x, y));

    int quotient;
    int remainder;
    test1.getQuotientAndRemainer(&quotient, &remainder);

    char message[LOG_LENGTH] = {0};
    snprintf(message, LOG_LENGTH, "quotient=%d, remainer=%d", quotient, remainder);
    print_log(FILE, LINE, message);

    return 0;
}
