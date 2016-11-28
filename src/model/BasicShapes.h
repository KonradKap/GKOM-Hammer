#pragma once

const std::vector<GLfloat> table_vertices = {
    0.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 0.0f,
    1.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
};

const std::vector<GLuint> table_indices = {
    0, 1, 2,
    1, 2, 3,
    2, 3, 6,
    6, 7, 3,
    0, 2, 4,
    4, 6, 2,
    0, 1, 5,
    5, 4, 0,
    1, 3, 5,
    3, 5, 7,
    4, 6, 5,
    5, 6, 7,
};
