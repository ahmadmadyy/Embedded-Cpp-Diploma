#include <iostream>
#include <vector>
//array: fixed size statically allocated, linear, stored in static memory, .stack or .bss
//vector: dynamics, variable size, stored in heap, linear container

void inputVector(std::vector<int> &nums)
{
    std::cout << "Please enter elements: " << std::endl;
    for(auto& element : nums)
    {
        std::cin >> element;
    }
}

// function overloading
bool inputVector(std::vector<int> &nums, bool &status)
{
    std::cout << "Please enter elements: " << std::endl;
    for(auto& element : nums)
    {
        std::cin >> element;
    }
    status = true;
    return status;
}

void outputVector(const std::vector<int> &nums) // const for protection as not changing the values
{
    std::cout << "Printing elements: " << std::endl;
    for(auto element : nums)
    {
        std::cout << element << std::endl;
    }
}

int main()
{
    std::vector<int> nums(5,0);
    std::vector<int> list;
    std::vector<int> intvec;
    list.assign(nums.begin(),nums.end()); //copy values
    inputVector(nums);
    outputVector(nums);
    intvec.push_back(100);
}

/*
To Loop:
1) for(int i=0;i<nums.size();i++)
2) for(auto it = nums.begin(); it != nums.end() ; ++it)
3) for (auto &element : nums)
*/










