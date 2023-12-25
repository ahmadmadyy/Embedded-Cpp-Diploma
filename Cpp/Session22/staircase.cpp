#include <iostream>

void staircase(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(j>i)
            {
                std::cout << " ";
            }
            else 
            {
                std::cout << "#";
            }
        }
        std::cout << std::endl;
    }
}


int main()
{
    int n;
    std::cout << "Enter a Number: " << std::endl;
    std::cin >> n;
    staircase(n);

}