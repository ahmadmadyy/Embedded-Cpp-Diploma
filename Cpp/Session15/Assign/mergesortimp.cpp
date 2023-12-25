#include <iostream>
#include <memory>
#include <vector>


template <class T>
void merge(std::vector<T> &vect, int left, int middle, int right) 
{
    // compute the length of subarrays
    auto const subArrayOne = middle - left + 1;
    auto const subArrayTwo = right - middle;

    // create the smart pointers pointing to the vectors
    // std::cout << " subArrayOne: " << subArrayOne << " " <<  "subArrayTwo: " << subArrayTwo << std::endl;
    std::vector<T> leftArray(subArrayOne);                                  
    std::vector<T> rightArray(subArrayTwo);

    // copy values into temp vectors
    for(auto i = 0; i<subArrayOne; i++)
    {
        leftArray[i] = vect[left+i];
        //printf("%d",1);
    }

    for(auto i = 0; i<subArrayTwo; i++)
    {
        rightArray[i] = vect[middle + i + 1];
        //printf("%d",2);
    }

    auto indexSubArrayOne= 0; // Initial index of first sub-array
    auto indexSubArrayTwo = 0; // Initial index of second sub-array
    auto indexMergedArray= left; // Initial index of merged array

    // Merge the temp vects back into vect
    while(indexSubArrayOne < subArrayOne && indexSubArrayTwo < subArrayTwo)
    {
        if(leftArray[indexSubArrayOne] <= rightArray[indexSubArrayTwo])
        {
            vect[indexMergedArray] = leftArray[indexSubArrayOne];
            //printf("%d",3);
            indexSubArrayOne++;
        }
        else 
        {
            vect[indexMergedArray] = rightArray[indexSubArrayTwo];
            indexSubArrayTwo++;
            //printf("%d",4);
        }
        indexMergedArray++;
    }

    // copy remaining elements of left, if any
    while (indexSubArrayOne < subArrayOne) 
    {
        vect[indexMergedArray] = leftArray[indexSubArrayOne];
        indexSubArrayOne++;
        indexMergedArray++;
        //printf("%d",5);
    }

    // copy remaining elements of right, if any
    while(indexSubArrayTwo < subArrayTwo)
    {
        vect[indexMergedArray] = rightArray[indexSubArrayTwo];
        indexSubArrayTwo++;
        indexMergedArray++;
        //printf("%d",6);
    }

}

// begin is for left index and end is
// right index of the sub-array
template <class T>
void mergeSort(std::vector<T> &vect, int begin, int end)
{
    if(begin >= end)
        return;
    auto middle = begin + (end - begin) / 2;
    mergeSort(vect, begin, middle); //left
    mergeSort(vect, middle + 1, end); //right
    merge(vect, begin, middle, end);
    // void merge(std::vector<T> &vect, int left, int middle, int right)
    //printf("%d",7);
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
    mergeSort(vect, 0, vect.size()-1);

    std::cout << "Sorted array: \n";
    print(vect);
    return 0;
}