#include "Sphere.h"

Sphere::Sphere() : Models() 
{

}

void Sphere::Init() {

	glGenBuffers(1, &this->VBO);
	printf("%d\n", this->VBO);

	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, this->size_points * sizeof(float), this->points, GL_STATIC_DRAW);

	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);


	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);



	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), NULL);
	glEnableVertexAttribArray(0);

	if (skip != 0) {
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
	}
}

void Sphere::Bind() {
	glBindVertexArray(this->VAO);
}

void Sphere::Draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 2880);
}