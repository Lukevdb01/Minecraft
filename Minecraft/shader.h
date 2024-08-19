#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include "glad/glad.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	unsigned int ID;
	Shader(const char* vertex_shader, const char* fragment_shader);
	void use();
	void destroy();

private:
	static std::string getfile_contents(const char* filename)
	{
		std::ifstream in(filename, std::ios::in | std::ios::binary);
		if (in)
		{
			std::string contents;
			in.seekg(0, std::ios::end);
			contents.resize(in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&contents[0], contents.size());
			in.close();
			return(contents);
		}
		throw(errno);
	}
	GLuint vertexShader, fragmentShader;
};

#endif // !SHADER_CLASS_H


