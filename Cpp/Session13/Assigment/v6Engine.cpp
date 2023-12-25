#include <iostream>
#include "v6Engine.h"

void V6Engine::Start()
{
    std::cout << "Start V6 Engine " << std::endl;
}

void V6Engine::Stop()
{
    std::cout << "Stop V6 Engine " << std::endl;
}

std::unique_ptr<Engine> MakeV6Engine()
{
    return std::make_unique<V6Engine>();
}