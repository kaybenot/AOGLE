#pragma once
#include "Renderer.hpp"
#include "Input.hpp"
#include <string>

namespace AOGLE
{
    class Window
    {
    private:
        SDL_Window* window;
        SDL_Event event;

    public:
        void create(Renderer& renderer, int width, int height, std::string title);
        void process_events(bool& quit, Input& input) noexcept;
        void clear(Renderer& renderer) noexcept;
        void present_frame(Renderer& renderer) noexcept;

        Window();
        ~Window() noexcept;
    };
} // namespace AOGLE
