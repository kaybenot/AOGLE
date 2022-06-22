#include "AOGLE_Window.hpp"
#include "AOGLE_Logger.hpp"
#include <stdexcept>

void AOGLE_Window::create(AOGLE_Renderer& renderer, int width, int height, std::string title)
{
    switch (renderer.Type)
    {
    case RendererType::OpenGL:
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        if(window == nullptr)
            throw std::runtime_error(SDL_GetError());

        renderer.context = SDL_GL_CreateContext(window);
        if(renderer.context == nullptr)
            throw std::runtime_error(SDL_GetError());
        break;
    
    default:
        break;
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

AOGLE_Window::AOGLE_Window()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        throw std::runtime_error(SDL_GetError());
}

AOGLE_Window::~AOGLE_Window()
{
    SDL_Quit();
}
