#include <iostream>
#include "Engine.h"

class V6Engine : public Engine
{
    void Start() override;
    void Stop() override;
};
std::unique_ptr<Engine> MakeV6Engine();