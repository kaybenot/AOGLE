#include "AOGLE_Renderer.hpp"

void AOGLE_Renderer::create(RendererType type)
{
    Type = type;
}

void AOGLE_Renderer::set_clear_color(glm::vec4 clear_color)
{
    glClearColor(clear_color.r, clear_color.g, clear_color.b, clear_color.a);
}

void AOGLE_Renderer::set_OGL_version(int major, int minor)
{
    OGL_major = major;
    OGL_minor = minor;
}
