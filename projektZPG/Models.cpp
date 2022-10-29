#include "Models.h"

void Models::GenerateVBO()
{
	//vertex buffer object (VBO)
	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, size_points * sizeof(float), points, GL_STATIC_DRAW);
}

void Models::GenerateVAO()
{
	//Vertex Array Object (VAO)
	glGenVertexArrays(1, &VAO); //generate the VAO
	glBindVertexArray(VAO); //bind the VAO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), NULL); //points
	glEnableVertexAttribArray(0); //enable vertex attributes
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float))); //colours or lightning
	glEnableVertexAttribArray(1); //enable vertex attributes
}

Models::Models()
{
}

Models::Models(const float in_points[], int size_points)
{
	this->VAO = 0;
	this->VBO = 0;
	this->points = in_points;
	this->size_points = size_points;
}

void Models::Init()
{
	GenerateVBO();
	GenerateVAO();
}

void Models::Bind()
{
	glBindVertexArray(VAO);
}

void Models::Draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 36);
}