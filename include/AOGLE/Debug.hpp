#pragma once
#include <glm/glm.hpp>

namespace AOGLE
{
    class Debug
    {
    private:
    public:
        glm::vec3 camera_pos = {0, 0, 0};

        void print_debug() noexcept;
    };
} // namespace AOGLE
