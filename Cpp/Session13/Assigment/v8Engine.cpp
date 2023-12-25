#include <iostream>
#include "v8Engine.h"

void V8Engine::Start()
    {
        std::cout << "Start V8 Engine " << std::endl;
    }

void V8Engine::Stop()
{
    std::cout << "Stop V8 Engine " << std::endl;
}

std::unique_ptr<Engine> MakeV8Engine()
{
    return std::make_unique<V8Engine>();
}