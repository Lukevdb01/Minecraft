#ifndef RENDERER_CLASS_H
#define RENDERER_CLASS_H

#include <Windows.h>
#include "glad/glad.h"

class Renderer
{
public:
	void setMatrices(GLuint ID);
	void render();

	void setProjection(GLuint ID, float fov, float aspect, float near, float far);
	void setCamera(GLuint ID, float x, float y, float z);
	void setTranslation(GLuint ID, float x, float y, float z);

public:
	GLuint VAO, VBO, EBO;
	void createBuffers();
	
private:
	
};

#endif // !RENDERER_CLASS_H

