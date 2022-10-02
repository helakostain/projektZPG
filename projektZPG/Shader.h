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

	static GLuint vertexShader; //vertex shader ID
	static GLuint fragmentShader; //fragment shader ID
	static GLuint shaderProgram; //shader program ID

	static void VertexShader(); //create and compile Vertex Shader
	static void FragmentShader(); //create and compile Fragment Shader
	static void ShaderProgram(); //create and compile Shader program
	
	static void LinkCheck(); //check if all shaders were linked correctly

	static void ShaderRun(); //create and compiles all shaders
public:
	Shader();

	static void Init();
};