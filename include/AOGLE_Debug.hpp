#pragma once
#include <glm/glm.hpp>

class AOGLE_Debug
{
private:
public:
    glm::vec3 camera_pos = {0, 0, 0};

    void print_debug() noexcept;
};
