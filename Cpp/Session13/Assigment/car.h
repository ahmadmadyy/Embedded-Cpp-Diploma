#pragma once
#include "Engine.h"
#include <iostream>

class Car
{
    public:
        Car(std::unique_ptr<Engine>&& engine) : m_engine(std::move(engine)) {}
        void Drive();
        void Stop();
    private:
        std::unique_ptr<Engine> m_engine;
};