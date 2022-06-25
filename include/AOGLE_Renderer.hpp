#pragma once
#include <glad/glad.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <glm/glm.hpp>

enum class RendererType
{
    OpenGL,
    Total
};

class AOGLE_Renderer
{
friend class AOGLE_Window;

private:
    SDL_GLContext context;
    int OGL_minor = 6;
    int OGL_major = 4;

public:
    RendererType Type;

    void create(RendererType type = RendererType::OpenGL);
    void set_clear_color(glm::vec4 clear_color);
    void set_OGL_version(int major, int minor);
};
