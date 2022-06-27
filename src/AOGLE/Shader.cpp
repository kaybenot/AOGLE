#include "Shader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <stdexcept>

namespace AOGLE
{
    void Shader::load(Renderer& renderer, std::string vs_file_path, std::string fs_file_path)
    {
        switch (renderer.Type)
        {
        case RendererType::OpenGL:
        {
            GLuint vs = glCreateShader(GL_VERTEX_SHADER);
            GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);

            std::string vs_code;
            std::ifstream vs_file(vs_file_path, std::ios::in);
            if(vs_file.is_open()){
                std::stringstream sstr;
                sstr << vs_file.rdbuf();
                vs_code = sstr.str();
                vs_file.close();
            }
            else
                throw std::runtime_error("Could not open vertex shader file" + vs_file_path);

            std::string fs_code;
            std::ifstream fs_file(fs_file_path, std::ios::in);
            if(fs_file.is_open()){
                std::stringstream sstr;
                sstr << fs_file.rdbuf();
                fs_code = sstr.str();
                fs_file.close();
            }
            else
                throw std::runtime_error("Could not open fragment shader file" + fs_file_path);

            GLint result = GL_FALSE;
            int info_log_len;

            char const * vsp = vs_code.c_str();
            glShaderSource(vs, 1, &vsp , NULL);
            glCompileShader(vs);

            glGetShaderiv(vs, GL_COMPILE_STATUS, &result);
            glGetShaderiv(vs, GL_INFO_LOG_LENGTH, &info_log_len);
            if(info_log_len > 0){
                std::vector<char> VertexShaderErrorMessage(info_log_len + 1);
                glGetShaderInfoLog(vs, info_log_len, NULL, &VertexShaderErrorMessage[0]);
                throw std::runtime_error(&VertexShaderErrorMessage[0]);
            }

            char const * fsp = fs_code.c_str();
            glShaderSource(fs, 1, &fsp , NULL);
            glCompileShader(fs);

            glGetShaderiv(fs, GL_COMPILE_STATUS, &result);
            glGetShaderiv(fs, GL_INFO_LOG_LENGTH, &info_log_len);
            if(info_log_len > 0){
                std::vector<char> FragmentShaderErrorMessage(info_log_len + 1);
                glGetShaderInfoLog(fs, info_log_len, NULL, &FragmentShaderErrorMessage[0]);
                throw std::runtime_error(&FragmentShaderErrorMessage[0]);
            }

            program = glCreateProgram();
            glAttachShader(program, vs);
            glAttachShader(program, fs);
            glLinkProgram(program);

            glGetProgramiv(program, GL_LINK_STATUS, &result);
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_log_len);
            if(info_log_len > 0){
                std::vector<char> ProgramErrorMessage(info_log_len + 1);
                glGetProgramInfoLog(program, info_log_len, NULL, &ProgramErrorMessage[0]);
                throw std::runtime_error(&ProgramErrorMessage[0]);
            }
            
            glDetachShader(program, vs);
            glDetachShader(program, fs);
            
            glDeleteShader(vs);
            glDeleteShader(fs);
            break;
        }
        
        default:
            break;
        }
    }

    void Shader::use(Renderer& renderer) noexcept
    {
        switch (renderer.Type)
        {
        case RendererType::OpenGL:
            glUseProgram(program);
            break;
        
        default:
            break;
        }
    }
} // namespace AOGLE
