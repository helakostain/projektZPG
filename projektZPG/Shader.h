#pragma once
//Include GLEW
#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>

class Shader
{
private:
	static const char* vertex_shader;
	static const char* fragment_shader;
	static GLuint shaderProgram;

	static void ShaderRun();
public:
	Shader();

	static void Init();
};