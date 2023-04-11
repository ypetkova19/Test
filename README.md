# Explanation

This Github project will do the following.

## STEP 1: Create Functions C++ class for different mathematical operations.
Example:
Functions.cpp
getSum, getAverage, getDifference, getProduct, getDivisionValue, getSquareRoot, getQuotient, getRemainder, etc...

## STEP 2: Create .HPP header file for each method in Functions Class.

## STEP 3: Create TestClass C++ class for testing the different methods in Functions Class.
Example:
TestClass.cpp

## STEP 4: Create .HPP header file for each method in TestClass.
## STEP 5: Create IS_TEST() macro function to compare the success/failure cases.
Example:
IS_TEST(5 == 5) ==> true
IS_TEST(5 == 6) ==> false

## STEP 6: Create TestClass which performs Good weather Unit Tests on each mathematical operation in Functions class.
Example:
IS_TEST(getQsrt(5, 5) == sqrt(5*5)) ===> success

## STEP 7: Create TestClass which performs Bad weather Unit Tests on each mathematical operation in Functions class.
Example:
IS_TEST(getQsrt(-5, 5) == sqrt(-5*5)) ===> fail, as one cannot take sqrt of a negative value

## STEP 8: Compiling...
//Compile
g++ -g TestClass.cpp -o TestClass.exe
OR
g++ -o TestClass TestClass.cpp
//Run
./TestClass.exe

OR

//Compile
g++ *.cpp -o output
//Run
./output.exe

OR

### Add the following to your BASH file.

#### In terminal, create file, if it doesn't exist:
touch ~/.bash_personal

#### Via terminal, open bash file:
vim ~/.bash_personal

#### Add the following to bash file, save, and close.
<=====START=====>
compile ()
{
    echo "Starting compile...";
    g++ *.cpp -o output
}

run ()
{
    echo "Executing...";
    ./output.exe
}
<=====END=====>

#### In Linux terminal:
source ~/.bash_personal

#### Execute:
compile && run


# Functions Class Methods

Function: getProduct(int a, int b)
Exceptions: overflow_error
Possible actions: Provided integers are too big and operation results in value overflow.
