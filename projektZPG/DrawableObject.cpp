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

DrawableObject::DrawableObject(const float points[], int size_points)
{
    this->vertex_shader = 
        "#version 330\n"
        "layout(location=0) in vec3 vp;"
        "layout(location=1) in vec3 vp2;"
        "out vec3 colour;"
        "uniform mat4 modelMatrix;"
        "uniform mat4 viewMatrix;"
        "uniform mat4 projectionMatrix;"
        "void main () {"
        "     gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * vec4(vp, 1.0);"
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
    this->shaders = new Shader(vertex_shader, fragment_shader);
    this->transformations = new Transformation();
    //Models::Init();
}

bool DrawableObject::SetUp()
{
    //this->shaders->shaderUseProgram();
    this->models->Bind();
    //Models::Bind();
    return true;
}


void DrawableObject::setFy(Direction dir) {
    this->transformations->applyFy(dir);
}
void DrawableObject::setFx(Direction dir) {
    this->transformations->applyFx(dir);
}
void DrawableObject::setRot(Rotation r) {
    this->transformations->setRotation(r);
}
void DrawableObject::setGrow(Growth g) {
    this->transformations->setGrowth(g);
}

void DrawableObject::Pos_mov(glm::vec3 a) {
    this->transformations->translate(a);
}

Shader& DrawableObject::getShader() {
    return *this->shaders;
}