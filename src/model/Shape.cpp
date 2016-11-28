#include "model/Shape.h"

#include <utility>

#include "commons/ScopeBind.h"

Shape::Shape() : 
        VAO(0),
        VBO(0),
        EBO(0) {

}

Shape::Shape(const std::vector<GLfloat> vertices,
             const std::vector<GLuint> indices,
             GLenum usage) {
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    const auto vao_guard = ScopeBind::guard(VAO);
    {
        const auto vbo_guard = ScopeBind::guard(GL_ARRAY_BUFFER, VBO);

        glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(GLfloat), vertices.data(), usage);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);

        //glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        //glEnableVertexAttribArray(1);
    }
    
    glGenBuffers(1, &EBO);
    const auto ebo_guard = ScopeBind::guard(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(GLuint), indices.data(), usage);
}

//Shape::Shape(const Shape& s) {
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glGenBuffers(1, &EBO);
//
//    const auto vao_guard = ScopeBind::guard(VAO);
//    {
//        copy_buffer(s.VBO, VBO, GL_ARRAY_BUFFER);
//        copy_buffer(s.EBO, EBO, GL_ELEMENT_ARRAY_BUFFER);
//
//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//        glEnableVertexAttribArray(0);
//    }
//}

//void Shape::copy_buffer(GLuint source, GLuint destination, GLenum usage) {
//    GLint size;
//    const auto read_guard = ScopeBind::guard(GL_COPY_READ_BUFFER, source);
//    glGetBufferParameteriv(GL_COPY_READ_BUFFER, GL_BUFFER_SIZE, &size);
//
//    const auto write_guard = ScopeBind::guard(GL_COPY_WRITE_BUFFER, destination);
//    glBufferData(GL_COPY_WRITE_BUFFER, size, nullptr, GL_STATIC_COPY);
//
//    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0l, 0l, size);
//}

Shape::Shape(Shape&& s) : 
        Shape() {

    swap(*this, s);
}

Shape& Shape::operator=(Shape s) {
    swap(*this, s);
    return *this;
}

Shape::~Shape() {
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO);
}

void swap(Shape& lhs, Shape& rhs) {
    std::swap(lhs.VBO, rhs.VBO);
    std::swap(lhs.VAO, rhs.VAO);
    std::swap(lhs.EBO, rhs.EBO);
}

int Shape::vertexCount() const {
    int nBufferSize = 0;
    glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &nBufferSize);
    return ( nBufferSize / sizeof(GLfloat) );
}

int Shape::indexCount() const {
    int nBufferSize = 0;
    glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &nBufferSize);
    return ( nBufferSize / sizeof(GLuint) );
}

void Shape::apply(const glm::mat4& matrix) {
}
