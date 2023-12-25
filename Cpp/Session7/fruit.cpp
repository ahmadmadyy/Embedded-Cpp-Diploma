#include <iostream>

class Fruit
{       
    private:
        int price;
        int weight;

    public:
        int calculatePrice()
        {
            return price * weight;
        }

        void setPrice(int p)
        {
            price = p;
        }

        void setWeight(int w)
        {
            weight = w;
        }

        int getPrice()
        {
            return price;
        }

        int getWeight()
        {
            return weight;
        }
};

int main()
{
    Fruit orange;
    orange.setPrice(100);
    orange.setWeight(2);
    auto total = orange.calculatePrice();
    std::cout << "Total Price: " << total << std::endl;
}