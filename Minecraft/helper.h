#pragma once
#include <glad/glad.h>

struct RenderCoords {
    static constexpr GLfloat vertices[] = {
        // Vertex positions        // Colors           // Texture coordinates
        // Back face
        -1.0f, -1.0f, -1.0f,      1.0f, 0.0f, 0.0f,  0.0f, 0.0f,  // V0
         1.0f, -1.0f, -1.0f,      1.0f, 0.0f, 0.0f,  1.0f, 0.0f,  // V1
         1.0f,  1.0f, -1.0f,      1.0f, 0.0f, 0.0f,  1.0f, 1.0f,  // V2
        -1.0f,  1.0f, -1.0f,      1.0f, 0.0f, 0.0f,  0.0f, 1.0f,  // V3

        // Front face
        -1.0f, -1.0f,  1.0f,      0.0f, 1.0f, 0.0f,  0.0f, 0.0f,  // V4
         1.0f, -1.0f,  1.0f,      0.0f, 1.0f, 0.0f,  1.0f, 0.0f,  // V5
         1.0f,  1.0f,  1.0f,      0.0f, 1.0f, 0.0f,  1.0f, 1.0f,  // V6
        -1.0f,  1.0f,  1.0f,      0.0f, 1.0f, 0.0f,  0.0f, 1.0f,  // V7

        // Left face
        -1.0f, -1.0f, -1.0f,      0.0f, 0.0f, 1.0f,  0.0f, 0.0f,  // V8
        -1.0f,  1.0f, -1.0f,      0.0f, 0.0f, 1.0f,  1.0f, 0.0f,  // V9
        -1.0f,  1.0f,  1.0f,      0.0f, 0.0f, 1.0f,  1.0f, 1.0f,  // V10
        -1.0f, -1.0f,  1.0f,      0.0f, 0.0f, 1.0f,  0.0f, 1.0f,  // V11

        // Right face
         1.0f, -1.0f, -1.0f,      1.0f, 0.0f, 1.0f,  0.0f, 0.0f,  // V12
         1.0f,  1.0f, -1.0f,      1.0f, 0.0f, 1.0f,  1.0f, 0.0f,  // V13
         1.0f,  1.0f,  1.0f,      1.0f, 0.0f, 1.0f,  1.0f, 1.0f,  // V14
         1.0f, -1.0f,  1.0f,      1.0f, 0.0f, 1.0f,  0.0f, 1.0f,  // V15

         // Top face
         -1.0f,  1.0f, -1.0f,      1.0f, 1.0f, 0.0f,  0.0f, 0.0f,  // V16
          1.0f,  1.0f, -1.0f,      1.0f, 1.0f, 0.0f,  1.0f, 0.0f,  // V17
          1.0f,  1.0f,  1.0f,      1.0f, 1.0f, 0.0f,  1.0f, 1.0f,  // V18
         -1.0f,  1.0f,  1.0f,      1.0f, 1.0f, 0.0f,  0.0f, 1.0f,  // V19

         // Bottom face
         -1.0f, -1.0f, -1.0f,      1.0f, 0.5f, 0.0f,  0.0f, 0.0f,  // V20
          1.0f, -1.0f, -1.0f,      1.0f, 0.5f, 0.0f,  1.0f, 0.0f,  // V21
          1.0f, -1.0f,  1.0f,      1.0f, 0.5f, 0.0f,  1.0f, 1.0f,  // V22
         -1.0f, -1.0f,  1.0f,      1.0f, 0.5f, 0.0f,  0.0f, 1.0f   // V23
    };

    static constexpr GLuint indices[] = {
        // Back face
        0, 1, 2,  // First triangle
        2, 3, 0,  // Second triangle

        // Front face
        4, 5, 6,  // First triangle
        6, 7, 4,  // Second triangle

        // Left face
        8, 9, 10, // First triangle
        10, 11, 8, // Second triangle

        // Right face
        12, 13, 14, // First triangle
        14, 15, 12, // Second triangle

        // Top face
        16, 17, 18, // First triangle
        18, 19, 16, // Second triangle

        // Bottom face
        20, 21, 22, // First triangle
        22, 23, 20  // Second triangle
    };
};
