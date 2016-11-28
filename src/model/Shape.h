#pragma once

#include <vector>

#include <GL/glew.h>
#include <GL/gl.h> 
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Shape {
    friend class ScopeBindShape;
    public:
        Shape();
        Shape(const std::vector<GLfloat> vertices,
              const std::vector<GLuint> indices,
              GLenum usage);

        Shape(const Shape& s) = delete;
        Shape(Shape&& s);
        Shape& operator=(Shape s);

        virtual ~Shape();

        friend void swap(Shape& lhs, Shape& rhs);

        int vertexCount() const;
        int indexCount() const;
        void apply(const glm::mat4& matrix);
    private:
        static void copy_buffer(GLuint source, GLuint destination, GLenum usage);

        GLuint VAO;
        GLuint VBO;
        GLuint EBO;
};
