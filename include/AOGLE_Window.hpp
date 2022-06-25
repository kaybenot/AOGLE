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
    void process_events(bool& quit);
    void clear(AOGLE_Renderer& renderer);
    void present_frame(AOGLE_Renderer& renderer);

    AOGLE_Window();
    ~AOGLE_Window();
};
