#pragma once

#include <vector>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Shader;

class Shape {
    friend class ScopeBindShape;
    public:
        enum ShapeData {
            VERTICES = 1<<0,
            NORMALS  = 1<<1,
            TEXTURES = 1<<2,
        };

        Shape();
        Shape(const std::vector<GLfloat>& vertices,
              const std::vector<GLuint>& indices,
              int data,
              GLenum usage = GL_STATIC_DRAW);

        //TODO:
        Shape(const Shape& s) = delete;
        Shape(Shape&& s);
        Shape& operator=(Shape s);

        virtual ~Shape();

        friend void swap(Shape& lhs, Shape& rhs);

        int vertexCount() const;
        int indexCount() const;

        void draw(const glm::vec3& position, const Shader& shader) const;
        void draw(const glm::mat4& transform, const Shader& shader) const;
    private:
        //static void copy_buffer(GLuint source, GLuint destination, GLenum usage);

        GLuint VAO;
        GLuint VBO;
        GLuint EBO;
};
