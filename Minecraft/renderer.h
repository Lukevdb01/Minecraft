#ifndef RENDERER_CLASS_H
#define RENDERER_CLASS_H

#include <Windows.h>
#include "glad/glad.h"

class Renderer
{
public:
	void setMatrices(GLuint ID);
	void render();

public:
	GLuint VAO, VBO, EBO;
	void createBuffers();
	
private:
	
};

#endif // !RENDERER_CLASS_H

