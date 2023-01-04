#include <iostream>

int main()
{
    int genuine[6] = {1, 1, 2, 2, 2, 8};
    int obj[6] = {};
    for(int i=0;i<6;++i)
    {
        std::cin >> obj[i];
    }

    for(int i=0;i<6;++i)
    {
        std::cout << genuine[i] - obj[i] << " ";
    }
}