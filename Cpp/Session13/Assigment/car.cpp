#include "car.h"

void Car::Drive()
{
    m_engine->Start();
}

void Car::Stop()
{
    m_engine->Stop();
}
