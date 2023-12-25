#include <iostream>
#include <array>
#include <algorithm>
using namespace std;


int main()
{
    std::array<int,5> list = {40,10,30,20,50};

    auto multiply_lambda = [](int &element) -> void
    {
        element*=2;
    };

    auto callback  = [](int &a,int &b) -> bool
    {
        return a > b;
    };
    
    std::for_each(list.begin(),list.end(),multiply_lambda);

    for(auto element : list)
    {
        std::cout << element << " " ;
    }
    std::cout << std::endl;

    std::sort(list.begin(),list.end(),callback);

    for(auto element : list)
    {
        std::cout << element << " " ;
    }
    std::cout << std::endl;
}