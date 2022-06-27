#pragma once
#include <glad/glad.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <glm/glm.hpp>

namespace AOGLE
{
    enum class RendererType
    {
        OpenGL,
        Total
    };

    class Renderer
    {
    friend class Window;

    private:
        SDL_GLContext context;
        int OGL_minor = 6;
        int OGL_major = 4;

    public:
        RendererType Type;

        void create(RendererType type = RendererType::OpenGL) noexcept;
        void set_clear_color(glm::vec4 clear_color) noexcept;
        void set_OGL_version(int major, int minor) noexcept;
    };
} // namespace AOGLE
