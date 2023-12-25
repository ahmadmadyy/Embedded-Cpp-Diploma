#include <iostream>
#include <unordered_map>
#include <string>

// Compiled in C++17

int main() 
{
    // also called hash table
    // Create an unordered_map with string keys and int values
    std::unordered_map<std::string, int> myMap;

    // Insert elements into the hash table
    myMap["apple"] = 1;
    myMap["banana"] = 2;
    myMap["cherry"] = 3;

    // Access elements in the hash table
    std::cout << "Value of apple: " << myMap["apple"] << std::endl;

    // Check if an element exists in the hash table
    if (myMap.count("banana") > 0) // count returns the cumber of occurrences of an element
    {
        std::cout << "Found banana!" << std::endl;
    }

    // Iterate over the elements in the hash table
    for (const auto& [key , value] : myMap) 
    {
        std::cout << key << ": " << value << std::endl;
    }
    std::cout << std::endl;

    // Remove an element from the hash table
    myMap.erase("cherry");

    for (const auto& [key , value] : myMap) 
    {
        std::cout << key << ": " << value << std::endl;
    }
    std::cout << std::endl;

    // Clear all elements from the hash table
    myMap.clear();

    return 0;
}
