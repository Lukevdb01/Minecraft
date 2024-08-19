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
	renderer->setMatrices(ShaderProgram->ID);

	// Game loop
    while (window->isRunning()) {
		window->ProcessMessages();

        // Render here
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ShaderProgram->use();
		renderer->render();

		// Swap front and back buffers
		window->SwapWindowBuffers();
    }

	return 0;
}