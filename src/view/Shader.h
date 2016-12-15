#pragma once

#include <string>
#include <functional>

#include <GL/glew.h>
#include <glm/glm.hpp>

class Shader {
    public:
        Shader();
        Shader(const Shader& s) = delete;
        Shader(const GLchar* vertex_path, const GLchar* fragment_path);
        Shader(Shader&& s);
        ~Shader();

        Shader& operator=(Shader s);
        friend void swap(Shader& lhs, Shader& rhs);

        void use() const;
        GLuint get_id() const;

        void setUniform(const char* name, const glm::vec3& value) const;
        void setUniform(const char* name, const glm::mat4& value) const;
        void setUniform(const char* name, GLuint value) const;
    private:
        class id_guard;
        std::string read_code(const GLchar* path) const;
        id_guard compile_shader(
            const std::string& code, 
            GLenum shader_type, 
            const GLchar* path) const;

        GLuint link_program(GLuint vertex_id, GLuint fragment_id) const;
        void print_errors(GLuint id, GLenum pname, 
                std::function<void (GLuint, GLenum, GLint*)> get_iv, 
                std::function<void (GLuint, GLsizei, GLsizei*, GLchar*)> get_info_log,
                const GLchar* path) const;
    public:
        GLuint id;
};

class Shader::id_guard {
    public:
        id_guard(GLuint id = 0) : id(id) {}
        ~id_guard() {
            glDeleteShader(id);
        }
        GLuint get() const {
            return id;
        }
    private:
        GLuint id;
};
