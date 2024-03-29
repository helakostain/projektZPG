#pragma once
//Include GLEW
#include <GL/glew.h>
//Include GLM
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "Observer.h"
#include "Camera.hpp"
#include "ShaderLoader.h"
#include "Light.hpp"

class Shader : public Observer, public ShaderLoader
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

	void passUniformLocation(const std::string& var, const glm::mat4& matrix) const;
	void passUniformLocation(const char* var, const glm::mat4& matrix) const;
	void passUniformLocation(const std::string& var, const glm::mat3& matrix) const;
	void passUniformLocation(const char* var, const glm::mat3& matrix) const;
	void passUniformLocation(const std::string& var, const glm::vec3& vector) const;
	void passUniformLocation(const char* var, const glm::vec3& vector) const;
	void passUniformLocation(const std::string& var, int32_t value) const;

	void passUniformLocation(const std::string& var, const float value) const;

	GLint getUniformLocation(const std::string& var) const;
	GLint getUniformLocation(const char* var) const;

	void applyLight(ColoredLight& light);
	void applyLight(PositionedLight& light);
	void applyLight(DirectionalLight& light);
	void applyLight(Spotlight& light);
	void typeChanged(gl::Light type, size_t lightIndex);
public:
	Shader(const char* vertex_path, const char* fragment_path);

	void UpdateMatrix();
	void setMatrix(glm::mat4 mvp);
	void Init();
	void shaderUseProgram();

	void updateView(const glm::mat4& view);
	void updateProjection(const glm::mat4& projection);
	void updatePosition(const glm::vec3& position);

	void colorChanged(glm::vec3 color, size_t lightIndex, gl::Light lightType);
	void positionChanged(glm::vec3 position, size_t lightIndex, gl::Light lightType);

	void notify(EventType eventType, void* object) override;

	void passUniformLocation(const char* var, int32_t value) const;
	void passUniformLocation(const char* var, const float value) const;
};