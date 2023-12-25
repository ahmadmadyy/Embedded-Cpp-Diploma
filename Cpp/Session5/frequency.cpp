/*
We are given an array of integer elements which contains duplicate values
and the task is to calculate the frequencies of the distinct elements 
present in an array and print the result.

a {3,3,5,8,9,8,9,10,17,10,11,17,10}

element : frequency
3 : 2
5 : 2
8 : 2
9 : 2
10 : 3
11 : 1
17 : 1

*/
#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    std::cout << "Element " << " " << "Frequency " << std::endl; 
    std::array<int,18> array = {3,3,5,8,9,8,9,10,17,10,11,17,10};
    int n = array.size();
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        if(visited[i]!=1)
        {
            int count = 1;
            for (int j = i+1; j < n; j++)
            {
                if(array[i]==array[j])
                {
                    count++;
                    visited[j]=1;
                }
            }
            std::cout <<array[i]<<"              "<<count<< std::endl;
        }
    }
}