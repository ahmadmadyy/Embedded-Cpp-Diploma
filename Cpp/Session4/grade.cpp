#include <iostream>

enum Grades
{
    MIN = 50,
    GOOD = 65,
    VERY_GOOD = 75,
    EXCELLENT = 85,
    MAX = 100
};

namespace Grade
{
    std::uint16_t grade{0};

    void WelcomeStudent()
    {
        std::cout << " Enter Grade:\n ";
        std::cin >> grade;
    }

    void evaluate_grade()
    {
        if(grade < MIN)
        {
            std::cout << "Failed\n";
        }
        else if(grade>=MIN & grade< GOOD)
        {
            std::cout << "Passed\n";
        }
        else if(grade>=GOOD && grade<VERY_GOOD)
        {
            std::cout << "Good\n";
        }
        else if(grade>=VERY_GOOD && grade<EXCELLENT)
        {
            std::cout << "Very Good\n";
        }
        else if(grade>=EXCELLENT && grade<=MAX)
        {
            std::cout << "Excellent\n";
        }
        else
        {
            std::cout << "Invalid Grade\n";
        }
    }
}

int main()
{
    
    while (1)
    {
        //Grade::WelcomeStudent();
        //Grade::evaluate_grade();
        int m = 2;
        int v = 3;
        int z = 4;
        int w = m=2 ? v:z;
        std::cout << "w= " << w << std::endl;
    }
}