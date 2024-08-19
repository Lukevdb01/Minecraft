#include <iostream>
#include "glad/glad.h"
#include "window.h"
#include "shader.h"
#include "renderer.h"
#include "stb/stb_image.h"

int main()
{
	int WIDTH = 800, HEIGHT = 600;

	Window* window = new Window("OpenGL", WIDTH, HEIGHT);
    if (!gladLoadGL())
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
	Shader* ShaderProgram = new Shader("shaders/vertex_shader.vert", "shaders/fragment_shader.frag");
	Renderer* renderer = new Renderer();

	renderer->createBuffers();

	ShaderProgram->use();
	renderer->setProjection(ShaderProgram->ID, 45.0f, WIDTH / HEIGHT, 0.1f, 100.0f);
	renderer->setCamera(ShaderProgram->ID, 0.0f, -45.0f, 55.0f);

	// Setup texture
	int width, height, nrChannels;
	unsigned char* data = stbi_load("content/grass.png", &width, &height, &nrChannels, 0);

	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}	
	stbi_image_free(data);

	ShaderProgram->use();
	glUniform1i(glGetUniformLocation(ShaderProgram->ID, "texture1"), 0);

	glEnable(GL_DEPTH_TEST);

	// Game loop
    while (window->isRunning()) {
		window->ProcessMessages();

        // Render here
		glClearColor(0.2f, 0.4f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ShaderProgram->use();

		// Bind the texture
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);

		// generate grid of cubes
		for (int x = -20; x < 20; x++)
		{
			for (int y = -20; y < 20; y++)
			{
				renderer->setTranslation(ShaderProgram->ID, x, y, 0);
				renderer->render();
			}
		}

		// Swap front and back buffers
		window->SwapWindowBuffers();
    }

	return 0;
}