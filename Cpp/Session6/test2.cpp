#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void Calculate(const std::vector<int> &list1, std::function<void(mutable int&, mutable int&)> const& swap)
{
  std::vector<int> list2 = {10,8,2,4,6};
  std::sort(list2.begin(),list2.end());
  for(auto num : list1)
  {
    swap(list1[num],list2[num]);
  }
}


int main()
{
  std::vector<int> list1 = {3,5,1,7,9};
  //std::vector<int> list2 = {10,8,2,4,6};
  std::sort(list1.begin(),list1.end());
  auto swap_main = [](int &x,int &y) -> void {
    int temp = x;
    x = y;
    y = temp;
    std::cout << "List1 Element: " << x << " " << "List2 Element: " << y << std::endl;
  };

  Calculate(list1,swap_main);
}
