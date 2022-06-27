#pragma once
#include "Renderer.hpp"

namespace AOGLE
{
    class Camera
    {
    private:
        glm::mat4 model;
        glm::mat4 view;
        glm::mat4 projecton;
        
    public:
        glm::vec3 pos;

        void calculate_projection(float FOV, float width, float height, float near, float far) noexcept;
        void calculate_MVP(const Renderer& renderer) noexcept;

        Camera() noexcept;
    };
} // namespace AOGLE
