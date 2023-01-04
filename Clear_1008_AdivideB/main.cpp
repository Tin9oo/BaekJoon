#include <iostream>
#include <iomanip>

int main()
{
    double a, b;
    double tmp;
    double rst;

    std::cin >> a >> b;

    tmp = (a)/b;
    rst = (double)tmp;

    std::cout << std::setprecision(10);
    std::cout << rst;
}