#pragma once
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>

class Shader; // dopredna deklarace (z duvodu krizoveho odkazu)

class Camera
{
private:
	Shader* m_shader;

	glm::vec3 eye; // Camera is at (4,3,-3), in World Space
	glm::vec3 target; // and looks at the origin
	glm::vec3 up;  // Head is up (set to 0,-1,0 to look upside-down)
public: 
	Camera();

	glm::mat4 getCamera();
};