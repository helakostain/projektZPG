#include "DrawableObject.h"

DrawableObject::DrawableObject()
{

}
DrawableObject::DrawableObject(std::vector<float> points)
{
    this->models = new Models(points);
    this->models->Init();

    //Models::Init();
}

bool DrawableObject::SetUp()
{
    Shader::Init();
    models[0].Bind();
    //Models::Bind();
    return true;
}
