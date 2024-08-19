#include <iostream>
#include "glad/glad.h"
#include "window.h"
#include "shader.h"
#include "renderer.h"

int main()
{
	Window* window = new Window("OpenGL", 800, 600);
    if (!gladLoadGL())
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
	Shader* ShaderProgram = new Shader("shaders/vertex_shader.vert", "shaders/fragment_shader.frag");
	Renderer* renderer = new Renderer();

	renderer->createBuffers();

	ShaderProgram->use();
	renderer->setProjection(ShaderProgram->ID, 45.0f, 800.0f / 600.0f, 0.1f, 100.0f);
	renderer->setCamera(ShaderProgram->ID, 0.0f, -45.0f, 55.0f);

	// Game loop
    while (window->isRunning()) {
		window->ProcessMessages();

        // Render here
		glClearColor(0.2f, 0.4f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ShaderProgram->use();
		// generate grid of cubes
		for (int x = -20; x < 20; x++)
		{
			for (int y = -20; y < 20; y++)
			{
				renderer->setTranslation(ShaderProgram->ID, x, y, 0);
				renderer->render();
			}
		}
		renderer->render();

		// Swap front and back buffers
		window->SwapWindowBuffers();
    }

	return 0;
}