#include <iostream>
#include <set>
#include <unordered_set>

int main()
{
    std::set<int> numbers = {1, 100, 10, 70, 100};
    std::multiset<int> multi_numbers = {1, 100, 10, 70, 100};

    std::cout << "set: ";
    for(auto& num: numbers) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "multiset: ";
    for(auto& num: multi_numbers) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::unordered_multiset<int> numbers_allow_duplicate = {1, 15 ,2 , 100, 130, 70, 100};
    std::cout << "unordered multiset: ";
    for(auto& num: numbers_allow_duplicate) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}