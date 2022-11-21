#include "DrawableObject.h"

DrawableObject::DrawableObject()
{
}

DrawableObject::DrawableObject(Models* model, const char* vertex_path, const char* fragment_path)
{
    this->models = model;
    this->models->Init();
    this->shaders = new Shader(vertex_path, fragment_path);
    this->transformations = new Transformation();
}

DrawableObject::DrawableObject(const float points[], int size_points, const char* vertex_path, const char* fragment_path)
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

Shader& DrawableObject::getShader() 
{
    return *this->shaders;
}