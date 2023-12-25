#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> list1(10), list2;

    list1.assign({1,2,3});
    list2.assign(5,100);

    std::cout << "List2: " ;
    for(auto element : list2)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    
    list2.assign(list1.begin(),list1.end());
    list1.reverse();

    std::cout << "List1: " ;
    for(auto element : list1)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "List2: " ;
    for(auto element : list2)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;


    return 0;
}