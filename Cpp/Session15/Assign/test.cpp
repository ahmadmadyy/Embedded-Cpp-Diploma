#include <iostream>
#include <array>
#include <memory>
#include <vector>

int main() {
    // Write C++ code here
    int mid =3;
    int left = 0;
    int right = 6;
    std::vector<int> array = {0,1,2,3,4,5,6};
    
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    // Create temp arrays
    // auto *leftArray = new int[subArrayOne],
        //  *rightArray = new int[subArrayTwo];

    std::shared_ptr<std::vector<int>> leftArray = 
                                    std::make_shared<std::vector<int>>(subArrayOne);
    std::shared_ptr<std::vector<int>> rightArray = 
                                    std::make_shared<std::vector<int>>(subArrayTwo);

  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        (*leftArray)[i] = array[left + i];

    for (auto j = 0; j < subArrayTwo; j++)
        (*rightArray)[j] = array[mid + 1 + j];
        
    for (auto i = 0; i < subArrayOne; i++) {
    std::cout << "leftArray[" << i << "] = " << (*leftArray)[i] << std::endl;
    }

    for (auto j = 0; j < subArrayTwo; j++) {
        std::cout << "rightArray[" << j << "] = " << (*rightArray)[j] << std::endl;
    }

}