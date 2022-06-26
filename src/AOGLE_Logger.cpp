#include "AOGLE_Logger.hpp"
#include <iostream>

void AOGLE_Logger::Log(std::string msg) noexcept
{
    std::cout << msg << std::endl;
}
