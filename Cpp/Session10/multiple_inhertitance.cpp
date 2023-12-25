
/*
every vehicle has a transmission type
* Transmission : has two types Auto , Manual
* Vehicle : is a base type has a transmission 
* Car : is a vehicle with Auto Transmission 
* MotorBike : is a vehicle with Manual Transmission
*/

#include <iostream>

class Transmission
{
    public:
        Transmission()
        {

        }
        void setTransmission(bool ptransmission)
        {
            transmission = ptransmission;
            std::cout << "Set Transmission with: " << ptransmission << std::endl;
        }
    private:
        bool transmission;
};

class Vehicle 
{
    public: 
        Vehicle()
        {
            
        }
        void StartVehicle()
        {
            std::cout << "Start Vehicle" << std::endl;
        }
        void StopVehicle()
        {
            std::cout << "Stop Vehicle" << std::endl;
        }
};

class Car : public Vehicle, public Transmission
{
    public:
        Car(int p_id) : id(p_id)
        {
            setTransmission(true);
        }
        ~Car()
        {
            StopVehicle();
            std::cout << "Stopped: " << id << std::endl;
        }
    private:
        int id;
};

class Motorbike : public Vehicle, public Transmission
{
    public:
        Motorbike(int p_id) : id(p_id)
        {
            setTransmission(false);
        }
        ~Motorbike()
        {
            StopVehicle();
            std::cout << "Stopped: " << id << std::endl;
        }
    private:
        int id;
};

int main()
{
    Car BMW(1);
    BMW.StartVehicle();
    Motorbike Honda(2);
    Honda.StartVehicle();
}