#include <iostream>
#include <array>
#include <algorithm>

void welcome(std::string str)
{
    std::cout << str << std::endl;
}

void fun2(int var)
{
    std::cout << "Variable = " << var << std::endl;
}

void fun1(void (*fptr)(int))
{
    int data = 10;
    fptr(data);
}

int main()
{
    // fun1(&fun2); //method 1

    void (*fptr)(void (*fptr)(int)) = nullptr;
    fptr = &fun1;
    fptr(fun2);                   // method 2

    void (*f_ptr)(std::string) = &welcome;
    f_ptr("Welcome");
}