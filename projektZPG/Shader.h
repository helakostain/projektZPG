#pragma once
//Include GLEW
#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>

class Shader
{
private:
	const char* vertex_shader;
	const char* fragment_shader;

	GLuint vertexShader; //vertex shader ID
	GLuint fragmentShader; //fragment shader ID
	GLuint shaderProgram; //shader program ID

	void VertexShader(); //create and compile Vertex Shader
	void FragmentShader(); //create and compile Fragment Shader
	void ShaderProgram(); //create and compile Shader program
	
	void LinkCheck(); //check if all shaders were linked correctly

	void ShaderRun(); //create and compiles all shaders
public:
	Shader(const char* in_vertex_shader, const char* in_fragment_shader);

	void Init();
};