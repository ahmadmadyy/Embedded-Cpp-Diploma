#include <iostream>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;

}

int main()
{
   //  int x=7;
    // int *p=&x;
  // std::cout << "p= " << p <<"  " << "x = " << x << std::endl; 
   // *p = 9;
   // std::cout << "p= " << p <<"  " << "x = " << x << std::endl; 

    int n1 = 8;
    int n2 = 10;

    swap(&n1,&n2);

    std::cout << "n1 = " << n1 << "  " << "n2 = " << n2 << std::endl;


}