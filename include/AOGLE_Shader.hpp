#pragma once
#include "AOGLE_Renderer.hpp"
#include <string>

class AOGLE_Shader
{
private:
    GLuint program;

public:
    void load(AOGLE_Renderer& renderer, std::string vs_file_path, std::string fs_file_path);
    void use(AOGLE_Renderer& renderer) noexcept;
};
