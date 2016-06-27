#pragma once
#include "System.hpp"

class Application
{
public:
    Application();
    void run();

private:
    System m_system;
};
