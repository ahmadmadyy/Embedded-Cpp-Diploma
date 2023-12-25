#include <iostream>
#include <array>
#include <algorithm>


int main()
{
    int x = 3;
    int y = 4;
    int z = 5;
    auto print = [&]() -> void 
    {
        x*=3;
        y*=2;
        z*=4;
        std::cout << " x = " << x << " y = " << y << " z = " << z <<std::endl;
    }; // capture by value, changing the value of x will output an error
    // solution: capture by reference (&x)

    auto print2 = [=]() -> void //capture by value(takes a copy)
    {
        std::cout << " x = " << x << " y = " << y << " z = " << z <<std::endl;
    };

    auto print3 = [&x,&y](int factor) -> void 
    {
        x+=factor;
        y-=factor;
        std::cout << " x = " << x << " y = " << y << std::endl;
    };

    print();
    print2();
    print3(2);
}