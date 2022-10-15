#include "DrawableObject.h"

void DrawableObject::DoTransformations(const double delta)
{
    this->transformations->Update(delta);
}

void DrawableObject::sendShaderMatrix()
{
    this->shaders->setMatrix(this->transformations->matrix());
}

DrawableObject::DrawableObject()
{

}

DrawableObject::DrawableObject(float points[], int size_points)
{
    this->vertex_shader = 
        "#version 330\n"
        "layout(location=0) in vec3 vp;"
        "layout(location=1) in vec3 vp2;"
        "out vec3 colour;"
        "uniform mat4 modelMatrix;"
        "void main () {"
        "     gl_Position = modelMatrix * vec4(vp, 1.0);"
        "     colour = vp2;"
        "}";
    this->fragment_shader = 
        "#version 330\n"
        "in vec3 colour;"
        "out vec4 frag_colour;"
        "void main () {"
        "    frag_colour = vec4(colour, 1.0);"
        "}";
    this->models = new Models(points, size_points);
    this->models->Init();
    this->transformations = new Transformation();
    //Models::Init();
}

bool DrawableObject::SetUp()
{
    this->shaders = new Shader(vertex_shader, fragment_shader);
    this->models->Bind();
    //Models::Bind();
    return true;
}
