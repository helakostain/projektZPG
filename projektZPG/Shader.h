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

	static GLuint vertexShader;
	static GLuint fragmentShader;
	static GLuint shaderProgram;

	static void VertexShader();
	static void FragmentShader();
	static void ShaderProgram();

	static void ShaderRun();
public:
	Shader();

	static void Init();
};