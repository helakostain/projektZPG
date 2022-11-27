#include "DrawableObject.hpp"

DrawableObject::DrawableObject()
{
}

DrawableObject::DrawableObject(Models* model, const char* vertex_path, const char* fragment_path, int size)
{
    this->models = model;
    this->models->Init();
    this->shaders = new Shader(vertex_path, fragment_path);
    this->transformations = new Transformation();
    this->isObject = false;
    this->id = size;
}

/*DrawableObject::DrawableObject(const float points[], int size_points, const char* vertex_path, const char* fragment_path)
{
    this->models = new Models(points, size_points);
    this->models->Init();
    this->shaders = new Shader(vertex_path, fragment_path);
    this->transformations = new Transformation();
}

DrawableObject::DrawableObject(const float points[], int size_points, Shader& shader)
{
    this->models = new Models(points, size_points);
    this->models->Init();
    this->shaders = &shader;
    this->transformations = new Transformation();
    this->texture = nullptr;
}

DrawableObject::DrawableObject(const float points[], int size_points, Shader& shader, shared_ptr<Texture> texture)
{
    this->models = new Models(points, size_points);
    this->models->Init();
    this->shaders = &shader;
    this->transformations = new Transformation();
    this->texture = texture;
}*/

DrawableObject::DrawableObject(Models* model, Shader& shader, int size)
{
    this->models = model;
    this->models->Init();
    this->shaders = &shader;
    this->transformations = new Transformation();
    this->texture = nullptr;
    this->isObject = false;
    this->id = size;
}

DrawableObject::DrawableObject(Models* model, Shader& shader, shared_ptr<Texture> texture, int size)
{
    this->models = model;
    this->models->Init();
    this->shaders = &shader;
    this->transformations = new Transformation();
    this->texture = texture;
    this->isObject = false;
    this->id = size;
}

DrawableObject::DrawableObject(Models* model, Shader& shader, shared_ptr<Texture> texture, int size, bool object)
{
    this->models = model;
    //this->models->Init();
    this->shaders = &shader;
    this->transformations = new Transformation();
    this->texture = texture;
    this->isObject = object;
    this->id = size;
}

void DrawableObject::DoTransformations(const double delta)
{
    this->transformations->Update(delta);
}

void DrawableObject::sendShaderMatrix()
{
    this->shaders->setMatrix(this->transformations->matrix());
}

bool DrawableObject::SetUp()
{
    this->shaders->Init();
    this->models->Bind();
    return true;
}

void DrawableObject::Pos_scale(float a)
{
    this->transformations->scale(a);
}

void DrawableObject::setFy(Direction dir) 
{
    this->transformations->applyFy(dir);
}
void DrawableObject::setFx(Direction dir)
{
    this->transformations->applyFx(dir);
}
void DrawableObject::setRot(Rotation r) 
{
    this->transformations->setRotation(r);
}
void DrawableObject::setGrow(Growth g) 
{
    this->transformations->setGrowth(g);
}

void DrawableObject::Pos_mov(glm::vec3 a) 
{
    this->transformations->translate(a);
}

void DrawableObject::Draw()
{
    this->models->Draw();
}

void DrawableObject::updateObject(const float delta)
{
    this->shaders->shaderUseProgram();
    //models->Bind();
    if (!isObject)
    {
        models->Bind();
        glStencilFunc(GL_ALWAYS, id, 0xFF);
    }
    transformations->Update(delta);
    sendShaderMatrix();
    if (isObject)
    {
        models->draw(id, this->shaders);
    }
    else
    {
        Draw();
    }
}

void DrawableObject::applyTexture(std::shared_ptr<Texture> texture)
{
}

void DrawableObject::rotate(float degree, glm::vec3 axis)
{
    this->transformations->rotate(degree, axis);
}

Shader& DrawableObject::getShader() 
{
    return *this->shaders;
}