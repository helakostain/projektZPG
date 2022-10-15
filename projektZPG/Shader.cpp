#include "Shader.h"

Shader::Shader(const char* in_vertex_shader, const char* in_fragment_shader)
{
	this->vertexShader = 0;
	this->fragmentShader = 0;
	this->shaderProgram = 0;
	this->vertex_shader = in_vertex_shader;
	this->fragment_shader = in_fragment_shader;
	this->Init();
}

void Shader::VertexShader()
{
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex_shader, NULL);
	glCompileShader(vertexShader);
}

void Shader::FragmentShader()
{
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
	glCompileShader(fragmentShader);
}

void Shader::ShaderProgram()
{
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, fragmentShader);
	glAttachShader(shaderProgram, vertexShader);
	glLinkProgram(shaderProgram);
}

void Shader::LinkCheck()
{
	GLint status;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
}

void Shader::ShaderRun()
{
	//create and compile shaders
	VertexShader();
	FragmentShader();
	ShaderProgram();

	LinkCheck();
}

void Shader::Init()
{
	//Shader::ShaderRun();
	this->ShaderRun();
	glUseProgram(shaderProgram);
}
