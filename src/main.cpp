#include "AOGLE.hpp"

int main(int argc, char* argv[])
{
    AOGLE_Renderer renderer;
    AOGLE_Window window;

    renderer.create();
    window.create(renderer, 800, 600, "xd");

    bool quit = false;
    while(!quit)
        window.process_events(quit);

    return 0;
}