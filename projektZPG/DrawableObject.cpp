#include "DrawableObject.h"

DrawableObject::DrawableObject()
{

}
DrawableObject::DrawableObject(std::vector<float> points)
{
    models[0] = Models(points);
    models[0].Init();
    //Models::Init();
}

bool DrawableObject::SetUp()
{
    Shader::Init();
    models[0].Bind();
    //Models::Bind();
    return true;
}
