#include <iostream>

// reference is an alias to the variable,
// another name given to the variable
// but has the same memory location and same value
// a reference has to point at something, without this 
// a reference is useless
// at declaration, defenition is needed

// a pointer can be defined without pointing at anything
// all pointers of any type have the same size, what differs is the next element(jump)

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;

}

int main()
{
    int n1 = 8;
    int n2 = 10;

    swap(n1,n2);

    std::cout << "n1 = " << n1 << "  " << "n2 = " << n2 << std::endl;

    int x = 5;
    int y = 9;
    int& num1 = x;
    int& num2 = y;
    std::cout << "x = " << x << " y = " << y << " num1 = " << num1 
                                                    << " num2 = " << num2 << std::endl;
    std::cout << "&x = " << &x << " &y = " << &y << " &num1 = " << &num1 
                                                    << " &num2 = " << &num2 << std::endl;
    std::cout << "size(num1) = " << sizeof(num1);
    return 0;
}