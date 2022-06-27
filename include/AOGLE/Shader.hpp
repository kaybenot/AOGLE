#pragma once
#include "Renderer.hpp"
#include <string>

namespace AOGLE
{
    class Shader
    {
    private:
        GLuint program;

    public:
        void load(Renderer& renderer, std::string vs_file_path, std::string fs_file_path);
        void use(Renderer& renderer) noexcept;
    };
} // namespace AOGLE
