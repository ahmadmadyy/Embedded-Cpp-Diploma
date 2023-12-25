#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <functional>

void Calculate(const std::array<int,5> &arr_num, std::function<void (int)> calculateSquare)
{
    for(const auto& num : arr_num)
    {
        calculateSquare(num);
    }
}

int main()
{
    std::array<int,5> nums = {6,7,9,4,5};
    std::sort(nums.begin(),nums.end());
    auto lambda_square = [] (int num) -> void
    {
        std::cout << "number " << num << " " << "square " << num * num << std::endl;
    };

    Calculate(nums,lambda_square);
}