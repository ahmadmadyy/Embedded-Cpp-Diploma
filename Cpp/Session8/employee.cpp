#include <iostream>
#include "employee.h"

    Employee::Employee(): m_id(0),m_salary(0),m_name("")
    {
        //this->m_id = 0;
        //this->m_salary = 0;
        //this->m_name = "";
    }

    Employee::Employee(const Employee& employee_copy) : m_id(employee_copy.m_id),
                                                        m_salary(employee_copy.m_salary),
                                                        m_name(employee_copy.m_name) 
                                                        // copy constructor
    {
        std::cout << "Copy constructor is callled\n" ;
        //this->m_id = employee_copy.m_id;
        //this->m_salary = employee_copy.m_salary;
        //this->m_name = employee_copy.m_name;
        // another way instead of initializer list
    }

    Employee::Employee(int id, int salary, std::string name):m_id(id),m_salary(salary),m_name(name)
    {
        this->m_id = id;
        this->m_salary = salary;
        this->m_name = name;
    }

    void Employee::setId(int id)
    {
        this->m_id = id;
    }

    Employee::~Employee()
    {
        std::cout << "Destructor of : " << getId() << std::endl;
    }

    void Employee::setSalary(int salary)
    {
        this->m_salary = salary;
    }

    void Employee::setName(std::string name)
    {
        this->m_name = name;
    }

    int Employee::getId()
    {
        return m_id;
    }

    int Employee::getSalary()
    {
        return m_salary;
    }

    std::string Employee::getName()
    {
        return m_name;
    }

    void Employee::display()
    {
        std::cout << "Employee Name: " << getName() << " " << "ID: " << getId() << " " 
        << "Salary: " << getSalary() << " " << std::endl;
    }
