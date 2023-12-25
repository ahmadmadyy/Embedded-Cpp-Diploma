#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void Calculate(std::vector<int>& list1, void (*swap)(int&, int&))
{
    std::vector<int> list2 = {10, 8, 2, 4, 6};
    std::sort(list2.begin(), list2.end());
    for (size_t i = 0; i < list1.size(); ++i)
    {
        swap(list1[i], list2[i]);
    }
}

int main()
{
    std::vector<int> list1 = {3, 5, 1, 7, 9};
    // std::vector<int> list2 = {10, 8, 2, 4, 6};
    std::sort(list1.begin(), list1.end());
    for(auto element : list1)
    {
        std::cout << "List1 Element: " << element << " " << std::endl;
    }

     std::cout << std::endl;

    auto swap_main = [](int &x, int &y) -> void
    {
        int temp = x;
        x = y;
        y = temp;
        std::cout << "List1 Element: " << x << " " << "List2 Element: " << y << std::endl;
    };

    Calculate(list1, swap_main);

    return 0;
}
