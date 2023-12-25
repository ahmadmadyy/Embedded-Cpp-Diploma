#pragma once
#include <memory>

struct Engine
{
    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual ~Engine() = default;
};