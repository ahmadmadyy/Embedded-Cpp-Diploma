#include <iostream>
#include <vector>

template <class T>
int binarySearch(std::vector<T> list,T var)
{
    int first = 0;
    int last = list.size()-1;
    int mid;
    while(first<=last)
    {
        mid = (first+last)/2;
        if(list[mid]==var)
        {
            return mid;
        }
        else if(list[mid]<var)
        {
            first = mid+1;
        }
        else 
        {
            last = mid-1;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> list {2,6,8,24,33,41};
    int key = 33;
    int index = binarySearch(list,key);
    if(index==-1)
    {
        std::cout << "Not found!" << std::endl;
    }
    else 
    {
        std::cout << "Found at index: " << index << std::endl;
    }
}