#include <iostream>
#include "Engine.h"

class V8Engine : public Engine
{
    void Start() override;
    void Stop() override;
};
std::unique_ptr<Engine> MakeV8Engine();