#include "AOGLE_Window.hpp"
#include "AOGLE_Logger.hpp"
#include <stdexcept>

void AOGLE_Window::create(AOGLE_Renderer& renderer, int width, int height, std::string title)
{
    switch (renderer.Type)
    {
    case RendererType::OpenGL:
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, renderer.OGL_major);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, renderer.OGL_minor);
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        if(window == nullptr)
            throw std::runtime_error(SDL_GetError());

        renderer.context = SDL_GL_CreateContext(window);
        if(renderer.context == nullptr)
            throw std::runtime_error(SDL_GetError());
        renderer.set_clear_color({0.0f, 0.0f, 0.0f, 1.0f});
        break;
    
    default:
        throw std::runtime_error("Unknown renderer type: "
            + std::to_string(static_cast<int>(renderer.Type)));
    }
}

void AOGLE_Window::process_events(bool& quit)
{
    while(SDL_PollEvent(&event) == 1)
    {
        if(event.type == SDL_QUIT)
            quit = true;
    }
}

void AOGLE_Window::clear(AOGLE_Renderer& renderer)
{
    switch (renderer.Type)
    {
    case RendererType::OpenGL:
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        break;
    
    default:
        throw std::runtime_error("Unknown renderer type: "
            + std::to_string(static_cast<int>(renderer.Type)));
    }
}

void AOGLE_Window::present_frame(AOGLE_Renderer& renderer)
{
    switch (renderer.Type)
    {
    case RendererType::OpenGL:
        SDL_GL_SwapWindow(window);
        break;
    
    default:
        throw std::runtime_error("Unknown renderer type: "
            + std::to_string(static_cast<int>(renderer.Type)));
    }
}

AOGLE_Window::AOGLE_Window()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        throw std::runtime_error(SDL_GetError());
}

AOGLE_Window::~AOGLE_Window()
{
    SDL_Quit();
}
