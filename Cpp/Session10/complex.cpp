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

    friend std::ostream& operator<<(std::ostream& output, const Complex &complex);

    private:
        float real;
        float img;
};

std::ostream& operator<<(std::ostream& output, const Complex &complex)
{
    output << "ostream: " << complex.real << " "<< "+ i" << complex.img << std::endl;
    return output; 
}


int main()
{
    Complex c1(2,5);
    Complex c2(3,5);
    Complex c3 = c1 + c2;
    //c3.display();
    std::cout << c3;

}