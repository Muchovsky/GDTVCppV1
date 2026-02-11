#include <iostream>

int main()
{
    std::cout << "You are a secret agent braking into a secure server room" << '\n';
    std::cout << "You need to enter the correct codes to continue ... " << '\n';

    const int a = 123;
    const int b = 23;
    const int c = 3;


    const int sum = a + b + c;
    const int product = a * b * c;

    std::cout << sum << '\n';
    std::cout << product << '\n';

    return 0;
}
