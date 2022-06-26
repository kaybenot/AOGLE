#pragma once
#include "AOGLE_Renderer.hpp"

class AOGLE_Camera
{
private:
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projecton;
    
public:
    glm::vec3 pos;

    void calculate_projection(float FOV, float width, float height, float near, float far) noexcept;
    void calculate_MVP(const AOGLE_Renderer& renderer) noexcept;

    AOGLE_Camera() noexcept;
};

