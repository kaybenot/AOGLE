#pragma once
#include "AOGLE_Renderer.hpp"
#include <string>

class AOGLE_Window
{
private:
    SDL_Window* window;
    SDL_Event event;

public:
    void create(AOGLE_Renderer& renderer, int width, int height, std::string title);
    void process_events(bool& quit) noexcept;
    void clear(AOGLE_Renderer& renderer) noexcept;
    void present_frame(AOGLE_Renderer& renderer) noexcept;

    AOGLE_Window();
    ~AOGLE_Window() noexcept;
};
