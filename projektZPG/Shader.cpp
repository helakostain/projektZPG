#include "Shader.h"
#include <glm/ext/matrix_float4x4.hpp>

Shader::Shader(const char* in_vertex_shader, const char* in_fragment_shader)
{
	this->vertexShader = 0;
	this->fragmentShader = 0;
	this->shaderProgram = 0;
	this->vertex_shader = in_vertex_shader;
	this->fragment_shader = in_fragment_shader;
	this->Init();
}

void Shader::UpdateMatrix()
{
}

void Shader::setMatrix(glm::mat4 modelMatrix)
{
	GLuint MatrixID = glGetUniformLocation(this->shaderProgram, "modelMatrix");
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &modelMatrix[0][0]);
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

GLint Shader::getUniformLocation(const char* var) const
{
	return glGetUniformLocation(this->shaderProgram, var);
}

void Shader::Init()
{
	//Shader::ShaderRun();
	this->ShaderRun();
	glUseProgram(shaderProgram);
}

void Shader::updateView(const glm::mat4& view) {
	//passUniformLocation("viewMatrix", view);
}

void Shader::updateProjection(const glm::mat4& projection) {
	//passUniformLocation("projectionMatrix", projection);
}