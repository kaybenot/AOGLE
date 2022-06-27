#include "Logger.hpp"
#include <iostream>

namespace AOGLE
{
    void Logger::Log(std::string msg) noexcept
    {
        std::cout << msg << std::endl;
    }
} // namespace AOGLE
