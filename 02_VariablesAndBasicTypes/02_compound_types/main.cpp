#include <iostream>

int main()
{
    int ival = 1024;
    int &refVal = ival;
    // int &refVal2;    /* error: a reference MUST be initialized */
    std::cout << "ival is: " << ival << std::endl;
    std::cout << "refVal is: " << refVal << std::endl;

    refVal = 2;
    std::cout << "ival is: " << ival << std::endl;
    std::cout << "refVal is: " << refVal << std::endl;

    int ii = refVal;
    std::cout << "ii is: " << ii << std::endl;


    int &refVal3 = refVal;
    int i = refVal;
    std::cout << "refVal3 is: " << refVal3 << std::endl;
    std::cout << "i is: " << i << std::endl;


    std::cout << "\nExercises:" << std::endl;
    std::cout << "\t2.16:" << std::endl;

    int i3 = 0, &ri3 = i3;
    double d = 0, &rd = d;

    rd = 3.14159;
    std::cout << "d = " << d << std::endl;

    rd = ri3;
    std::cout << "rd = " << rd << std::endl;

    i3 = rd;
    std::cout << "i3 = " << i3 << std::endl;

    ri3 = d;
    std::cout << "ri3 = " << ri3 << std::endl;


    std::cout << "\t2.17:" << std::endl;

    int i4, &ri4 = i4;
    i4 = 5;
    ri4 = 10;
    std::cout << i4 << " " << ri4 << std::endl;


    int i5 = 42;
    int *pi5 = 0;
    int *pi5_2 = &i5;
    std::cout << "pi5_2 = " << *pi5_2 << std::endl;
    int *pi5_3;

    pi5_3 = pi5_2;
    std::cout << "pi5_3 = " << *pi5_3 << std::endl;
    std::cout << "pi5_2 = " << *pi5_2 << std::endl;
    pi5_2 = 0;
    std::cout << "pi5_2 = " << pi5_2 << std::endl;


    int zero = 0;
    int one = 1;
    int *ptest_1 = 0;
    int *ptest_2 = &zero;
    int *ptest_3 = &one;

    if (ptest_1) { std::cout << "ptest_1 = " << ptest_1 << std::endl; }
    if (ptest_2) { std::cout << "ptest_2 = " << ptest_2 << std::endl; }
    if (ptest_3) { std::cout << "ptest_3 = " << ptest_3 << std::endl; }


    int j = 42;
    int *pj = &j;
    *pj = *pj * *pj;
    std::cout << "j is " << j << std::endl;
    std::cout << "pj is " << *pj << std::endl;


    int iii = 42;
    const int & riii = iii;
    int & riii_1 = iii;
    riii_1 = 0;
    std::cout << riii << std::endl;


    return 0;
}