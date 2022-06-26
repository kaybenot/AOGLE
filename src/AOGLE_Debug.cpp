#include "AOGLE_Debug.hpp"
#include <imgui.h>

void AOGLE_Debug::print_debug() noexcept
{
    ImGui::SetNextWindowSize({250, 100}, ImGuiCond_FirstUseEver);
    ImGui::Begin("Debug Window", (bool*)0, ImGuiWindowFlags_NoResize);

    ImGui::Text("Camera position");
    ImGui::PushItemWidth(40.0f); ImGui::InputFloat("x:", &camera_pos.x); ImGui::SameLine();
    ImGui::PushItemWidth(40.0f); ImGui::InputFloat("y:", &camera_pos.y); ImGui::SameLine();
    ImGui::PushItemWidth(40.0f); ImGui::InputFloat("z:", &camera_pos.z);

    ImGui::End();
}
