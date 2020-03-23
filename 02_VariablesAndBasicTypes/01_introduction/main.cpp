#include <iostream>

int main()
{
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;

    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;

    char c = 'a';
    wchar_t cw = L'a';
    char c_arr[] = "a";
    wchar_t cw_arr[] = L"a";

    double d = 10.;
    std::cout << d << std::endl;

    int month = 07;
    std::cout << month << std::endl;

    std::cout << "\062\t\x4d" << std::endl;

    int in = 3.14;
    double Double = 5.0L;

    return 0;

    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
    
    int sum = 0, val = 1;
    while (val <= 10)
    {
        sum += val;
        ++val;
    }
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;

    sum = 0, val = 0;
    while (std::cin >> val)
        sum += val;

    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;

    return 0;
}