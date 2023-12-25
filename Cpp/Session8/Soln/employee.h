
#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <string>

//class declaration
class employee
{

public:
    employee(int salary);
    explicit employee(int argument, std::string first_name, int &salary);
    void setName(std::string name);
    std::string getName() const;
    int getSalary();
    void setSalary(int salary);
    int getId() const;
private:
    int id;
    int age;
    int &m_salary;
    std::string name;
};

#endif