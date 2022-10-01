#include "Debug.hpp"
#include <imgui.h>

namespace AOGLE
{
    void Debug::debug_logic(Input input) noexcept
    {
        if(input.get_key_press(SDLK_a))
            camera_pos.x -= 0.1f;
        if(input.get_key_press(SDLK_d))
            camera_pos.x += 0.1f;
        if(input.get_key_press(SDLK_w))
            camera_pos.y += 0.1f;
        if(input.get_key_press(SDLK_s))
            camera_pos.y -= 0.1f;
        if(input.get_key_press(SDLK_q))
            camera_pos.z -= 0.1f;
        if(input.get_key_press(SDLK_e))
            camera_pos.z += 0.1f;
    }

    void Debug::print_debug() noexcept
    {
        ImGui::SetNextWindowSize({250, 100}, ImGuiCond_FirstUseEver);
        ImGui::Begin("Debug Window", (bool*)0, ImGuiWindowFlags_NoResize);

        ImGui::Text("Camera position");
        ImGui::PushItemWidth(40.0f); ImGui::InputFloat("X, ", &camera_pos.x); ImGui::SameLine();
        ImGui::PushItemWidth(40.0f); ImGui::InputFloat("Y, ", &camera_pos.y); ImGui::SameLine();
        ImGui::PushItemWidth(40.0f); ImGui::InputFloat("Z", &camera_pos.z);

        ImGui::End();
    }
} // namespace AOGLE
