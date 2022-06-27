#pragma once
#include <string>

namespace AOGLE
{
    class Logger
    {
    private:
    public:
        static void Log(std::string msg) noexcept;
    };
} // namespace AOGLE
