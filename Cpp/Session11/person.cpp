#include <iostream>

template <class T>
void swap(T &a,T &b) // done in compile time, compile time polymorphism
{
    T temp = a; //copy constructor is called
    a = b; // assigment operator overload
    b = temp; // assigment operator overload
}

class Person
{   
    public: 
        Person(std::string pname, int page) : name(pname), age(page)
        {

        }

        Person(const Person& person) //copy constuctor
        {
            this->name = person.name;
            this->age = person.age;
        }

        Person& operator=(const Person& person) //operator overload
        {
            this->name = person.name;
            this->age = person.age;
            return *this;
        }

        std::string getName()
        {
            return name;
        }

        int getAge()
        {
            return age;
        }

    private:
        std::string name;
        int age;
};

int main()
{
    Person p1("Ahmed",23);
    Person p2("Ali",14);
    std::cout << "1st person name before swapping: " << p1.getName() << " , age: " <<
                                                        p1.getAge() << std::endl;
    swap<Person>(p1,p2);

    std::cout << "1st person name after swapping: " << p1.getName() << " , age: " <<
                                                        p1.getAge() << std::endl;
}