#include <iostream>
#include <iostream>
#include <list>

int main()
{
    std::list<int> list1 = {7, 5, 16, 8};
    auto it = list1.end();
    list1.insert(it,9);

    std::cout << "Printing list1 elements: ";
    for(auto& element : list1)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    list1.push_back(17);
    list1.push_front(17);
    list1.emplace_back(17);

    std::cout << "Printing list1 elements after insertion: ";
    for(auto iterator = list1.begin(); iterator != list1.end(); ++iterator)
    {
        std::cout << *iterator << " ";
    }
    std::cout << std::endl;

    list1.sort();
    list1.unique();
    std::cout << "Printing list1 elements after sorting and removing duplicates: ";
    for(auto iterator = list1.begin(); iterator != list1.end(); ++iterator)
    {
        std::cout << *iterator << " ";
    }
    std::cout << std::endl;
    
    auto list2 = std::list<int>{1,2,3,4};
    std::cout << "Printing list2 elements: ";
    for(auto& element : list2)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    list2.sort();
    list1.merge(list2);

    std::cout << "Printing list1 elements after sorting and merging elements: ";
    for(auto& element : list1)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

}