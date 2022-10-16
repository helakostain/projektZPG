#pragma once
//Include GLEW
#include <GL/glew.h>

#include <glm/mat4x4.hpp>

#include <stdio.h>
#include <stdlib.h>

#include "CameraObserver.h"
#include <string>
//class Camera; // dopredna deklarace (z duvodu krizoveho odkazu)

class Shader : public CameraObserver
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

	void updateView(const glm::mat4& view) override;
	void updateProjection(const glm::mat4& projection) override;
	void updatePosition(const glm::vec3& position) override;

	void shaderUseProgram();
};