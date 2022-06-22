#pragma once
#include <SDL.h>
#include <SDL_opengl.h>

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

public:
    RendererType Type;

    void create(RendererType type = RendererType::OpenGL);
};
