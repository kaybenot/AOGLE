#pragma once
#include "AOGLE_Renderer.hpp"
#include <string>
#include <vector>

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

class AOGLE_Mesh
{
private:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    GLuint vao;
    GLuint vbo;
    GLuint ebo;

    void load_model(const AOGLE_Renderer& renderer);
    
public:
    bool import_from_file(const AOGLE_Renderer& renderer, const std::string& file) noexcept;
    void draw(const AOGLE_Renderer& renderer) noexcept;
};
