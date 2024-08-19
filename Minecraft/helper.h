#pragma once
#include <glad/glad.h>

struct RenderCoords {
    static constexpr GLfloat vertices[] = {
        // Back face
        -1.0f, -1.0f, -1.0f,  // V0
         1.0f, -1.0f, -1.0f,  // V1
         1.0f,  1.0f, -1.0f,  // V2
        -1.0f,  1.0f, -1.0f,  // V3

        // Front face
        -1.0f, -1.0f,  1.0f,  // V4
         1.0f, -1.0f,  1.0f,  // V5
         1.0f,  1.0f,  1.0f,  // V6
        -1.0f,  1.0f,  1.0f   // V7
    };

    static constexpr GLuint indices[] = {
        // Back face
        0, 1, 2,
        2, 3, 0,

        // Front face
        4, 5, 6,
        6, 7, 4,

        // Left face
        0, 4, 7,
        7, 3, 0,

        // Right face
        1, 5, 6,
        6, 2, 1,

        // Top face
        3, 2, 6,
        6, 7, 3,

        // Bottom face
        0, 1, 5,
        5, 4, 0
    };
};
