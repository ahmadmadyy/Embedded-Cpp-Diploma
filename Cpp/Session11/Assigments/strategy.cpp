#include <iostream>
#include <algorithm>
#include <vector>

struct Strategy
{
    //Algorithm Interface
    virtual void calculateConsumption()=0;
};

struct Fuel : public Strategy
{
    public: 
        Fuel(int x, int y, double z) : speed(x), tank_volume(y), fuel_eff_factor(z) {}

        void calculateConsumption() override
        {
            std::cout << "Fuel Consumption : " << Fuel::getSpeed() / (Fuel::getVolume() * 
                                                    Fuel::getFuelFactor()) << std::endl;
            // speed is the car's current speed in miles per hour.
            // tank_volume is the car's tank volume in gallons.
            // fuel_eff_factor is a factor that represents the car's fuel efficiency.
        }

        int getSpeed()
        {
            return speed;
        }

        int getVolume()
        {
            return tank_volume;
        }

        double getFuelFactor()
        {
            return fuel_eff_factor;
        }

    private: 
        int speed;
        int tank_volume;
        double fuel_eff_factor;
};

struct Electric : public Strategy
// Battery Consumption (kWh/100 km) = (Battery Current * 
                        // Battery Voltage) / (V_speed * Efficiency)

{
    public: 
        Electric(int a, int b, int c, double d) : speed(a), battery_I(b), battery_V(c), 
                                                                    efficiency(d) {}

        void calculateConsumption() override
        {
            std::cout << "Battery Consumption : " << (Electric::getI() * Electric::getV()) / 
                        (Electric::getSpeed() * Electric::getefficiency()) << std::endl;
        }

        int getSpeed()
        {
            return speed;
        }

        int getV()
        {
            return battery_V;
        }

        int getI()
        {
            return battery_I;
        }

        double getefficiency()
        {
            return efficiency;
        }

    private:
        int speed; 
        int battery_I;
        int battery_V;
        double efficiency;

};

struct Cars
{
    Cars(Strategy *stgy) : strategy(stgy)
    {
        
    }

    void calculateConsumption()
    {
        strategy->calculateConsumption();
    }

    Strategy *strategy; //Ptr to implementation : pimpl idiom 
};

int main()
{
    Fuel Porsche(70,15,0.4);
    Electric BMW(70,355,26,0.5);

    Cars _911GT3RS(&Porsche);
    Cars BMWi8(&BMW);

    _911GT3RS.calculateConsumption();
    BMWi8.calculateConsumption();
}