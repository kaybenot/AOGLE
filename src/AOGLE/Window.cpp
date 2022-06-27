#include "Window.hpp"
#include "Logger.hpp"
#include <stdexcept>
#include <imgui.h>
#include <imgui_impl_sdl.h>
#include <imgui_impl_opengl3.h>

namespace AOGLE
{
    void Window::create(Renderer& renderer, int width, int height, std::string title)
    {
        switch (renderer.Type)
        {
        case RendererType::OpenGL:
        {
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, renderer.OGL_major);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, renderer.OGL_minor);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
            SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
            SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

            window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
            if(window == nullptr)
                throw std::runtime_error(SDL_GetError());

            renderer.context = SDL_GL_CreateContext(window);
            if(renderer.context == nullptr)
                throw std::runtime_error(SDL_GetError());

            if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress))
                throw std::runtime_error("Failed to initialize OpenGL context");

            glEnable(GL_DEPTH_TEST);
            glEnable(GL_MULTISAMPLE);

            ImGui::CreateContext();
            ImGuiIO& io = ImGui::GetIO();
            ImGui::StyleColorsDark();
            ImGui_ImplSDL2_InitForOpenGL(window, renderer.context);
            ImGui_ImplOpenGL3_Init("#version 460");

            renderer.set_clear_color({0.0f, 0.0f, 0.0f, 1.0f});
            break;
        }
        default:
            throw std::runtime_error("Unknown renderer type: "
                + std::to_string(static_cast<int>(renderer.Type)));
        }
    }

    void Window::process_events(bool& quit) noexcept
    {
        while(SDL_PollEvent(&event) == 1)
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if(event.type == SDL_QUIT)
                quit = true;
        }
    }

    void Window::clear(Renderer& renderer) noexcept
    {
        switch (renderer.Type)
        {
        case RendererType::OpenGL:
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplSDL2_NewFrame();
            ImGui::NewFrame();
            break;
        
        default:
            break;
        }
    }

    void Window::present_frame(Renderer& renderer) noexcept
    {
        switch (renderer.Type)
        {
        case RendererType::OpenGL:
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            SDL_GL_SwapWindow(window);
            break;
        
        default:
            break;
        }
    }

    Window::Window()
    {
        if(SDL_Init(SDL_INIT_VIDEO) != 0)
            throw std::runtime_error(SDL_GetError());
    }

    Window::~Window() noexcept
    {
        SDL_Quit();
    }
} // namespace AOGLE
