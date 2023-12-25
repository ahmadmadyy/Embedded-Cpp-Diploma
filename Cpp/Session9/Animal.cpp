#include <iostream>

class Animal
{
    public: 
        virtual void makeSound() = 0;
        virtual ~Animal() = default;
};

class Dog : public Animal
{
    void makeSound()
    {
        std::cout << "Bark" << std::endl;
    }
};

class Cat : public Animal
{
    void makeSound()
    {
        std::cout << "Meow" << std::endl;
    }
};

class Cow : public Animal
{
    void makeSound()
    {
        std::cout << "Moow" << std::endl;
    }
};

int main()
{
    Animal *animal;

    Dog dog;
    animal = &dog;
    animal->makeSound();

    Cat cat;
    animal = &cat;
    animal->makeSound();

    Cow cow;
    animal = &cow;
    animal->makeSound();
}