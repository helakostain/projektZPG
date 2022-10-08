#include "Models.h"

// quad with colours
float Models::points[] = {
	-.5f, -.5f, .5f, 1, 1, 1, 0, 1,
   -.5f, .5f, .5f, 1, 1, 0, 0, 1,
   .5f, .5f, .5f, 1 ,  0, 0, 0, 1 ,
   .5f, -.5f, .5f, 1 ,  0, 1, 0, 1 ,
};

float Models::points2[] = {
	-1.5f, -.5f, .5f, 1, 1, 1, 0, 1,
   -1.5f, .5f, .5f, 1, 1, 0, 0, 1,
   1.5f, .5f, .5f, 1 ,  0, 0, 0, 1 ,
   1.5f, -.5f, .5f, 1 ,  0, 1, 0, 1 ,
};

GLuint Models::VAO = 0;
GLuint Models::VBO = 0;

Models::Models()
{
	this->Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.01f, 100.0f);
	this->View = glm::lookAt(
		glm::vec3(10, 10, 10), // Camera is at (4,3,-3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	this->Model = glm::mat4(1.0f);
}

void Models::GenerateVBO()
{
	//vertex buffer object (VBO)
	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
}

void Models::GenerateVAO()
{
	//Vertex Array Object (VAO)
	glGenVertexArrays(1, &VAO); //generate the VAO
	glBindVertexArray(VAO); //bind the VAO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), NULL); //quad points
	glEnableVertexAttribArray(0); //enable vertex attributes
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(4 * sizeof(float))); //quad colours
	glEnableVertexAttribArray(1); //enable vertex attributes
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