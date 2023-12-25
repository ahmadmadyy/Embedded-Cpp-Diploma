#include <iostream>
#include <vector>

template <class T>
void swap(T *x, T *y) 
{ 
    T temp = *x; 
    *x = *y; 
    *y = temp; 
} 

template <class T>
void selectionSort(std::vector<T> &vect)
{
    T min_index;
    for(int i=0;i<vect.size()-1;i++)
    {
        min_index = i;
        for(int j = i+1; j<vect.size();j++)
        {
            if (vect[j] < vect[min_index]) 
            {
                min_index = j; 
            }
        }
        swap(&vect[min_index],&vect[i]);
    }
}

template <class T>
void print(std::vector<T> &vect)
{
    for(auto element : vect)
    {
        std::cout << element << " " ;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vect {30,55,2,6,20,7,21,15,10,5};
    selectionSort(vect);
    print(vect);

    std::vector<float> vect2 {30.7,55.8,2.9,6.45,20.8,7.8};
    selectionSort(vect2);
    print(vect2);
}







