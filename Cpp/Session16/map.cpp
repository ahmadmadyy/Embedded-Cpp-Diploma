#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>

// Compiled in C++17

std::pair<int,int> g_pair(8,10);
std::unordered_map<int, std::string> x_unordered_map;

int main()
{
    std::map<std::string, int> myMap;

    myMap.insert(std::make_pair<std::string, int>("Neymar", 11)); 
	myMap.insert(std::make_pair<std::string, int>("Mohamed Salah", 11)); 

    std::map<int, int> quiz;   // quiz_id , time limit
	// insert elements in random order
	quiz.insert(std::make_pair<int, int>(1, 40)); 
	quiz.insert(std::pair<int, int>(2, 30));
	quiz.insert(std::pair<int, int>(3, 50));
	quiz.insert(std::pair<int, int>(4, 20));
	quiz.insert(std::pair<int, int>(5, 100));
	quiz.insert(std::pair<int, int>(6, 200));
	quiz[7]=10;	 // another way of inserting a value in a map

    for(auto& pair : quiz)
	{
		auto key = pair.first;
		auto value = pair.second;
	}

    for (auto& [key, value]: quiz) 
    {
        std::cout << key << " has value " << value << std::endl;
    }
    // another way
    // printing map quiz
	std::map<int, int>::iterator itr;
	std::cout << "\nThe map quiz is : \n";
	std::cout << "\tKEY\tELEMENT\n";
	for (itr = quiz.begin(); itr != quiz.end(); ++itr) 
    {
		std::cout << '\t' << itr->first << '\t' << itr->second << '\n';
	}
	std::cout << std::endl;

    // assigning the elements from quiz to quiz2
    std::map<int, int> quiz2(quiz.begin(), quiz.end());

    // print all elements of the map quiz2
	std::cout << "\nThe map quiz2 after" << " assign from quiz is : \n";
	std::cout << "\tKEY\tELEMENT\n";
	for (itr = quiz2.begin(); itr != quiz2.end(); ++itr) 
    {
		std::cout << '\t' << itr->first << '\t' << itr->second << '\n';
	}
    std::cout << std::endl;

    // remove all elements up to element with key=3 in quiz2
    std::cout << "\n quiz2 after removal of"
			" elements less than key=3 : \n";
	std::cout << "\tKEY\tELEMENT\n";
    quiz2.erase(quiz2.begin(),quiz2.find(3));
    for (itr = quiz2.begin(); itr != quiz2.end(); ++itr) 
    {
		std::cout << '\t' << itr->first << '\t' << itr->second << '\n';
	}
    std::cout << std::endl;

    // remove all elements with key = 4
 	int num;
	num = quiz2.erase(4);
	std::cout << "\ngquiz2.erase(4) : ";
	std::cout << num << " removed \n";
	std::cout << "\tKEY\tELEMENT\n";
	for (itr = quiz2.begin(); itr != quiz2.end(); ++itr) 
    {
		std::cout << '\t' << itr->first << '\t' << itr->second << '\n';
	}
    std::cout << std::endl;

    // lower bound and upper bound for map gquiz1 key = 5
	std::cout << "gquiz1.lower_bound(5) : " << "\tKEY = ";
	auto it = quiz2.lower_bound(5);
	std::cout << it->first << '\t';
	std::cout << "\tELEMENT = " << it->second << std::endl;
	std::cout << "gquiz1.upper_bound(5) : " << "\tKEY = ";
	std::cout << quiz2.upper_bound(5)->first << '\t';
	std::cout << "\tELEMENT = " << quiz2.upper_bound(5)->second << std::endl;

    return 0;
}