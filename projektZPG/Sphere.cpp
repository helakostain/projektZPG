#include "Sphere.hpp"

Sphere::Sphere() : Models() {
	this->points = sphere;
	this->size_points = sizeof(sphere);

	this->valuesInRow = 6;
	this->skip = 3;
	this->values = 3;
	this->VAO = 0;
	this->VBO = 0;
}

void Sphere::Init() {
	glGenBuffers(1, &this->VBO);

	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, this->size_points * sizeof(float), this->points, GL_STATIC_DRAW);

	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	glVertexAttribPointer(0, values, GL_FLOAT, GL_FALSE, valuesInRow * sizeof(float), NULL);
	glEnableVertexAttribArray(0);

	if (skip != 0) {
		glVertexAttribPointer(1, values, GL_FLOAT, GL_FALSE, valuesInRow * sizeof(float), (void*)(skip * sizeof(float)));
		glEnableVertexAttribArray(1);
	}
}

void Sphere::Bind() {
	glBindVertexArray(this->VAO);
}
void Sphere::Draw() {
	glDrawArrays(GL_TRIANGLES, 0, 2880);
}