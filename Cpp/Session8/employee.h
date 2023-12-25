#pragma once
#include <iostream>
#include <vector>
class Employee
{
    public:
        Employee();
        Employee::Employee(const Employee& employee_copy); // copy constructor
        explicit Employee(int id, int salary, std::string name);
        // force it to use the parametrized contstructor
        // prevent automatic type conversion
        // the constructor will not be implicitly 
        // invoked by the compiler for implicit type 
        // conversions, ensuring that only explicit, 
        // user-requested conversions are performed.
        ~Employee();

        //setters
        void setName(std::string name);
        void setId(int id);
        void setSalary(int salary);

        //getters
        std::string getName();
        int getId();
        int getSalary();
        void display();

    private:
        int m_id;
        int m_salary;
        std::string m_name;

};