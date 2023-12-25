#include <iostream>

class Complex
{
    public:
        Complex(float r = 0, float i = 0) : real(r),img(i)
        {

        }

        Complex operator+(const Complex &obj)
        {
            Complex result;
            result.real = this->real + obj.real;
            result.img = this->img + obj.img;
            return result;
        }

        void display()
        {
            std::cout << real << " "<< "+ i" << img << std::endl;
        }

    private:
        float real;
        float img;
};


int main()
{
    Complex c1(2,5);
    Complex c2(3,5);
    Complex c3 = c1 + c2;
    c3.display();

}