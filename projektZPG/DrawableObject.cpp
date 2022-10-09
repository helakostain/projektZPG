#include "DrawableObject.h"

const char* DrawableObject::vertex_shader =
"#version 330\n"
"layout(location=0) in vec4 vp;"
"layout(location=1) in vec4 vp2;"
"out vec4 colour;"
"void main () {"
"     gl_Position = vp;"
"     colour = vp2;"
"}";
const char* DrawableObject::fragment_shader =
"#version 330\n"
"in vec4 colour;"
"out vec4 frag_colour;"
"void main () {"
"     frag_colour = colour;"
"}";

DrawableObject::DrawableObject()
{
}

DrawableObject::DrawableObject(float points[], int size_points)
{
    this->models = new Models(points, size_points);
    this->models->Init();
    //Models::Init();
}

bool DrawableObject::SetUp()
{
    this->shaders = new Shader(vertex_shader, fragment_shader);
    this->models->Bind();
    //Models::Bind();
    return true;
}
