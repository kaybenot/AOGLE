#pragma once
#include <functional>
#include <vector>

namespace AOGLE
{
    template <typename T>
    class Event
    {
    private:
        std::vector<std::function<T>> actions;

    public:
        std::vector<T> invoke() noexcept
        {
            std::vector<T> out;
            for(std::function<T> a : actions)
                out.push_back(a());
            return out;
        }
        void add(std::function<T> function) noexcept
        {
            actions.push_back(function);
        }
    };
} // namespace AOGLE
