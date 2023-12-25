#include "car.h"
#include "v6Engine.h"
#include "v8Engine.h"

int main()
{
    auto V6Engine1 = std::make_unique<V6Engine>();
    Car Mercedes_C180(std::move(V6Engine1));
    Mercedes_C180.Drive();
    Mercedes_C180.Stop();

    Car Fiat_Tipo(MakeV6Engine());
    Fiat_Tipo.Drive();
    Fiat_Tipo.Stop();

    Car BMW_i8(MakeV8Engine()); 
    BMW_i8.Drive();
    BMW_i8.Stop();

}

/*
        g++ -o careng main.cpp car.cpp v6Engine.cpp v8Engine.cpp
*/