#include <iostream>
#include <vector>

using namespace std;

void miniMaxSum(vector<int> arr) 
{
    int max = 0;
    int min = 0;
    int sum = 0;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
    }
    min = sum;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    int max_n = max;
    max = sum - min;
    min = sum - max_n;
    std::cout << min << " " << max << std::endl;
}

int main()
{
    long long int maxElement = INT_MIN;
    std::cout << maxElement;
}