#pragma once
#include "Renderer.hpp"
#include <string>
#include <vector>

namespace AOGLE
{
    struct Vertex
    {
        glm::vec3 pos;
        glm::vec3 normal;
        glm::vec2 texcoord;
    };

    struct Texture
    {
        unsigned int id;
        std::string type;
    };

    class Mesh
    {
    private:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;

        GLuint vao;
        GLuint vbo;
        GLuint ebo;

        void load_model(const Renderer& renderer) noexcept;
        
    public:
        bool import_from_file(const Renderer& renderer, const std::string& file) noexcept;
        void draw(const Renderer& renderer) noexcept;
    };
} // namespace AOGLE
