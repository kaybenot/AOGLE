#include "AOGLE_Shader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

void AOGLE_Shader::load(AOGLE_Renderer& renderer, std::string vs_file_path, std::string fs_file_path)
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
            std::cerr << "Could not open vertex shader file" + vs_file_path;

        std::string fs_code;
        std::ifstream fs_file(vs_file_path, std::ios::in);
        if(fs_file.is_open()){
            std::stringstream sstr;
            sstr << fs_file.rdbuf();
            fs_code = sstr.str();
            fs_file.close();
        }
        else
            std::cerr << "Could not open fragment shader file" + vs_file_path;

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
            printf("%s\n", &VertexShaderErrorMessage[0]);
        }

        char const * fsp = fs_code.c_str();
        glShaderSource(fs, 1, &fsp , NULL);
        glCompileShader(fs);

        // Check Fragment Shader
        glGetShaderiv(fs, GL_COMPILE_STATUS, &result);
        glGetShaderiv(fs, GL_INFO_LOG_LENGTH, &info_log_len);
        if(info_log_len > 0){
            std::vector<char> FragmentShaderErrorMessage(info_log_len + 1);
            glGetShaderInfoLog(fs, info_log_len, NULL, &FragmentShaderErrorMessage[0]);
            std::cerr << &FragmentShaderErrorMessage[0];
        }

        // Link the program
        printf("Linking program\n");
        program = glCreateProgram();
        glAttachShader(program, vs);
        glAttachShader(program, fs);
        glLinkProgram(program);

        // Check the program
        glGetProgramiv(program, GL_LINK_STATUS, &result);
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_log_len);
        if(info_log_len > 0){
            std::vector<char> ProgramErrorMessage(info_log_len + 1);
            glGetProgramInfoLog(program, info_log_len, NULL, &ProgramErrorMessage[0]);
            std::cerr << &ProgramErrorMessage[0];
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

void AOGLE_Shader::use(AOGLE_Renderer& renderer)
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