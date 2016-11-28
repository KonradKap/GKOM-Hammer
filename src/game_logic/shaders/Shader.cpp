#include "Shader.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include "game_logic/exceptions/ShaderException.h"

Shader::Shader() :
        id() {

}

Shader::Shader(const GLchar* vertex_path, const GLchar* fragment_path) {
    const auto vertex_id = 
        compile_shader(read_code(vertex_path), GL_VERTEX_SHADER, vertex_path);
    const auto fragment_id = 
        compile_shader(read_code(fragment_path), GL_FRAGMENT_SHADER, fragment_path);

    id = link_program(vertex_id.get(), fragment_id.get());
}

Shader::Shader(Shader&& s) :
        Shader() {

    swap(*this, s);
}

Shader& Shader::operator=(Shader s) {
    swap(*this, s);
    return *this;
}

void swap(Shader& lhs, Shader& rhs) {
    std::swap(lhs.id, rhs.id);
}

std::string Shader::read_code(const GLchar* path) const {
    std::ifstream shader_file(path);
    shader_file.exceptions(std::ifstream::badbit);

    std::stringstream shader_stream;
    shader_stream << shader_file.rdbuf();
    return shader_stream.str();
}

Shader::id_guard Shader::compile_shader(const std::string& code, GLenum shader_type, const GLchar* path) const {
    GLuint shader_id = glCreateShader(shader_type);
    auto c_code = code.c_str();
    glShaderSource(shader_id, 1, &c_code, NULL);
    glCompileShader(shader_id);
    print_errors(shader_id, GL_COMPILE_STATUS, glGetShaderiv, glGetShaderInfoLog, path);
    return id_guard(shader_id);
}

GLuint Shader::link_program(GLuint vertex_id, GLuint fragment_id) const {
    const auto program_id = glCreateProgram();
    glAttachShader(program_id, vertex_id);
    glAttachShader(program_id, fragment_id);
    glLinkProgram(program_id);
    glDetachShader(program_id, vertex_id);
    glDetachShader(program_id, fragment_id);
    print_errors(program_id, GL_LINK_STATUS, glGetProgramiv, glGetProgramInfoLog, "linking");
    return program_id;
}

void Shader::print_errors(GLuint id, GLenum pname, 
        std::function<void (GLuint, GLenum, GLint*)> get_iv, 
        std::function<void (GLuint, GLsizei, GLsizei*, GLchar*)> get_info_log,
        const GLchar* path) const {

    GLint success;
    get_iv(id, pname, &success);
    if (!success) {
        GLchar infoLog[512];
        get_info_log(id, sizeof(infoLog), nullptr, infoLog);
        std::cerr << infoLog << std::endl;
        throw ShaderException("Compilation failed at: " + std::string(path));
    }
}

Shader::~Shader() {
    glDeleteProgram(id);
}

void Shader::use() const {
    glUseProgram(id);
}

GLuint Shader::get_id() const {
    return id;
}
