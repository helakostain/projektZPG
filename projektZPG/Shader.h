#pragma once
//Include GLEW
#include <GL/glew.h>

#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "Observer.h"
#include "Camera.hpp"

class Shader : public Observer
{
private:
	//Camera* m_camera;

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

	//GLint getUniformLocation(const char* var) const;

	void passUniformLocation(const std::string& var, const glm::mat4& matrix) const;
	void passUniformLocation(const char* var, const glm::mat4& matrix) const;
	void passUniformLocation(const std::string& var, const glm::mat3& matrix) const;
	void passUniformLocation(const char* var, const glm::mat3& matrix) const;
	void passUniformLocation(const std::string& var, const glm::vec3& vector) const;
	void passUniformLocation(const char* var, const glm::vec3& vector) const;

	GLint getUniformLocation(const std::string& var) const;
	GLint getUniformLocation(const char* var) const;
public:
	Shader(const char* in_vertex_shader, const char* in_fragment_shader);

	void UpdateMatrix();
	void setMatrix(glm::mat4 mvp);
	void Init();

	void updateView(const glm::mat4& view);
	void updateProjection(const glm::mat4& projection);
	void updatePosition(const glm::vec3& position);

	void notify(EventType eventType, void* object) override;

	void shaderUseProgram();
};