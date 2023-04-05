#include <iostream>
using namespace std;


#define FILE __FILE__
#define LINE __LINE__
#define FILE_AND_LINE (FILE, LINE)

int main() {

    // calling the function
    //tbd();

    // cout << "F:%s L:%d Test print\n" << FILE << LINE;
    printf("F:%s L:%d Test print\n", FILE, LINE);

    return 0;
}