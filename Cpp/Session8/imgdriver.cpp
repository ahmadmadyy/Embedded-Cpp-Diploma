#include "image.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<std::uint8_t>> vect
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Image I1(vect);
    I1.showImage();
    Image I2(I1);
    I2.showImage();
}