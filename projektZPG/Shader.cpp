#include "Shader.h"

const char* Shader::vertex_shader =
"#version 330\n"
"layout(location=0) in vec4 vp;"
"layout(location=1) in vec4 vp2;"
"out vec4 colour;"
"void main () {"
"     gl_Position = vp;"
"     colour = vp2;"
"}";
const char* Shader::fragment_shader =
"#version 330\n"
"in vec4 colour;"
"out vec4 frag_colour;"
"void main () {"
"     frag_colour = colour;"
"}";

GLuint Shader::shaderProgram = 0;

Shader::Shader()
{
}

void Shader::ShaderRun()
{
	//create and compile shaders
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex_shader, NULL);
	glCompileShader(vertexShader);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
	glCompileShader(fragmentShader);
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, fragmentShader);
	glAttachShader(shaderProgram, vertexShader);
	glLinkProgram(shaderProgram);

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

void Shader::Init()
{
	Shader::ShaderRun();
	glUseProgram(shaderProgram);
}
