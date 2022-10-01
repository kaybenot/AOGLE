#pragma once
#include <SDL.h>

namespace AOGLE
{
    class Input
    {
    friend class Window;

    private:
        static const int KEY_NUM = 322;
        bool keys[KEY_NUM];

    public:
        bool get_key_press(SDL_KeyCode code);

        Input();
    };
} // namespace AOGLE
