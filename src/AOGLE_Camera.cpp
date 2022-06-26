#include "AOGLE_Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>

void AOGLE_Camera::calculate_projection(float FOV, float width, float height, float near, float far) noexcept
{
    projecton = glm::perspective(glm::radians(FOV), width / height, near, far);
}

void AOGLE_Camera::calculate_MVP(const AOGLE_Renderer& renderer) noexcept
{
    view = glm::lookAt(
        pos,
        glm::vec3(0, 0, 0),
        glm::vec3(0, 1, 0)
    );

    glm::mat4 model = glm::mat4(1.0f);

    glm::mat4 MVP = projecton * view * model;

    switch (renderer.Type)
    {
    case RendererType::OpenGL:
        glUniformMatrix4fv(0, 1, GL_FALSE, &MVP[0][0]);
        break;
    
    default:
        break;
    }
}

AOGLE_Camera::AOGLE_Camera() noexcept
{
    calculate_projection(60.0f, 800.0f, 600.0f, 0.1f, 100.0f);
}
