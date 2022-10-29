#include "Shader.h"

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

void Shader::ShaderRun() //create and compile shaders
{
	VertexShader();
	FragmentShader();
	ShaderProgram();

	LinkCheck();
}

void Shader::passUniformLocation(const std::string& var, const glm::mat4& matrix) const 
{
	passUniformLocation(var.c_str(), matrix);
}

void Shader::passUniformLocation(const char* var, const glm::mat4& matrix) const 
{
	const auto model = getUniformLocation(var);
	glUniformMatrix4fv(model, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::passUniformLocation(const std::string& var, const glm::vec3& vector) const 
{
	passUniformLocation(var.c_str(), vector);
}

void Shader::passUniformLocation(const char* var, const glm::vec3& vector) const 
{
	const auto location = getUniformLocation(var);
	glProgramUniform3f(shaderProgram, location, vector.x, vector.y, vector.z);
}

void Shader::passUniformLocation(const std::string& var, const glm::mat3& matrix) const 
{
	passUniformLocation(var.c_str(), matrix);
}

void Shader::passUniformLocation(const char* var, const glm::mat3& matrix) const 
{
	const auto location = getUniformLocation(var);
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

GLint Shader::getUniformLocation(const std::string& var) const
{
	return getUniformLocation(var.c_str());
}

GLint Shader::getUniformLocation(const char* var) const 
{
	return glGetUniformLocation(shaderProgram, var);
}

Shader::Shader(const char* vertex_path, const char* fragment_path) : ShaderLoader(vertex_path, fragment_path, &this->shaderProgram)
{
	//this->vertexShader = 0;
	//this->fragmentShader = 0;
	//this->shaderProgram = 0;
	this->vertex_shader = vertex_path;
	this->fragment_shader = fragment_path;
	//this->Init();
}

void Shader::UpdateMatrix()
{
}

void Shader::setMatrix(glm::mat4 modelMatrix)
{
	GLuint MatrixID = glGetUniformLocation(this->shaderProgram, "modelMatrix");
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &modelMatrix[0][0]);
}

void Shader::Init()
{
	//this->ShaderRun();
	glUseProgram(shaderProgram);
}

void Shader::shaderUseProgram()
{
	glUseProgram(shaderProgram);
}

void Shader::updateView(const glm::mat4& view) 
{
	passUniformLocation("viewMatrix", view);
}

void Shader::updateProjection(const glm::mat4& projection) 
{
	passUniformLocation("projectionMatrix", projection);
}

void Shader::updatePosition(const glm::vec3& position) 
{
	passUniformLocation("cameraPosition", position);
}

void Shader::notify(EventType eventType, void* object)
{
	if (eventType == EventType::CameraMoved)
	{
		Camera& camera = *((Camera*)object);
		updateView(camera.view());
		updatePosition(camera.position());
		updateProjection(camera.project());
	}
}