#include "DrawableObject.h"

DrawableObject::DrawableObject()
{
    Models::Init();
}

bool DrawableObject::SetUp()
{
    Shader::Init();
    Models::Bind();
    return true;
}
