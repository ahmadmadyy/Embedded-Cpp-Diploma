#include "employee.h"
#include "manager.h"

#include <iostream>
#include <vector>

employee::employee(int salary) : m_salary(salary)
{

}
//parameterized constructor
employee::employee(int argument, std::string first_name, int &salary) :
                                             id(argument),
                                             name(first_name),
                                             m_salary(salary)
{
    std::cout << "paramterized Constructor : info Salary "
    << m_salary << std::endl;
}

void employee::setName(std::string name)
{
    this->name = name;
}

std::string employee::getName() const
{
    return name;
}

int employee::getSalary()
{
    return  m_salary;
}

void employee::setSalary(int salary)
{
    this->m_salary = salary;
}

int employee::getId() const
{
    return id;
}

void displaySalaries(const std::vector<employee*> &employees)
{
    for(auto emp : employees)
    {
        std::cout <<"id " << emp->getId()  << 
        "\nSalary: " << emp->getSalary() << std::endl;
    }
}

int main()
{
    int id = 5;
    int salary = 1000;
    int salary_manager = 5000;
    std::string name = "Mohamed";
   
    employee* manager_ptr = new Manager(id, name, salary_manager); //dynamically allocated in heap
    employee* employee_ptr = new employee(1, name, salary); //dynamically allocated in heap

    std::cout << "new name " << manager_ptr->getName() << std::endl;
   
    std::vector<employee*> employees(2);
    employees.push_back(manager_ptr);
    employees.push_back(employee_ptr);

    displaySalaries(employees);

    delete manager_ptr;
    delete employee_ptr;
return 0;
}