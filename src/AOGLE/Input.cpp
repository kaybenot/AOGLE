#include "Input.hpp"
#include <cstring>

namespace AOGLE
{
    bool Input::get_key_press(SDL_KeyCode code)
    {
        return keys[code];
    }

    Input::Input()
    {
        std::memset(keys, (int)false, sizeof(bool) * KEY_NUM);
    }

} // namespace AOGLE

