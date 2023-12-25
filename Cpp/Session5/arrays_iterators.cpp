#include <iostream>
#include <array>

int main()
{
    std::array<int,3> list;
    //std::array<int,3>::iterator iterator;
    list.at(0); //list[0]
    std::array<int,3>::iterator myArray = list.data();
    auto myArray2 = list.data(); // same as line before
    std::cout << "Please Enter values: \n";
    for (auto iterator = list.begin(); iterator != list.end(); ++iterator) 
    //auto copies the same datatype
    {
        std::cin >> *iterator;
    }
    
    for (auto iterator = list.begin(); iterator != list.end(); ++iterator)
    {
        std::cout << "Array Element: " << *iterator << std::endl;
    }
    

}