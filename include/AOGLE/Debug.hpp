#pragma once
#include "Input.hpp"
#include <glm/glm.hpp>

namespace AOGLE
{
    class Debug
    {
    private:
    public:
        glm::vec3 camera_pos = {0, 0, 0};

        void debug_logic(Input input) noexcept;
        void print_debug() noexcept;
    };
} // namespace AOGLE
