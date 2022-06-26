#include "AOGLE_Mesh.hpp"
#include <fstream>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

void AOGLE_Mesh::load_model(const AOGLE_Renderer& renderer) noexcept
{
    switch (renderer.Type)
    {
    case RendererType::OpenGL:
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
        
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texcoord));
        break;
    
    default:
        break;
    }
}

bool AOGLE_Mesh::import_from_file(const AOGLE_Renderer& renderer, const std::string& file) noexcept
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(file,
        aiProcess_CalcTangentSpace | aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType);
    if(scene == nullptr)
        return false;

    if(!scene->HasMeshes())
        return false;
    for(unsigned int i = 0; i < scene->mNumMeshes; i++)
    {
        if(i > 0) // TODO: Multimesh support
            break;
        aiMesh* mesh = scene->mMeshes[i];
        for(unsigned int j = 0; j < mesh->mNumVertices; j++)
        {
            vertices.push_back({
                { mesh->mVertices[j].x, mesh->mVertices[j].y, mesh->mVertices[j].z },
                { mesh->mNormals[j].x, mesh->mNormals[j].y, mesh->mNormals[j].z },
                { mesh->mTextureCoords[i][j].x, mesh->mTextureCoords[i][j].y }
            });
        }
        for(unsigned int j = 0; j < mesh->mNumFaces; j++)
        {
            indices.push_back(static_cast<unsigned int>(mesh->mFaces[j].mIndices[0]));
            indices.push_back(static_cast<unsigned int>(mesh->mFaces[j].mIndices[1]));
            indices.push_back(static_cast<unsigned int>(mesh->mFaces[j].mIndices[2]));
        }

        // TODO: Texture loading
    }

    load_model(renderer);
    return true;
}

void AOGLE_Mesh::draw(const AOGLE_Renderer& renderer) noexcept
{
    switch (renderer.Type)
    {
    case RendererType::OpenGL:
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
        break;
    
    default:
        break;
    }
}
