#include "ShaderInstances.h"

ShaderInstances* ShaderInstances::sInstance = nullptr;

ShaderInstances& ShaderInstances::instance()
{
    if (not sInstance)
    {
        sInstance = new ShaderInstances();
    }
    return *sInstance;
}

ShaderInstances::ShaderInstances() : 
    _blinn("LightShader.txt", "Blinn.txt"), 
    _constant("defaultvertex.txt", "defaultfragment.txt"),
    _lambert("LightShader.txt", "Lambert.txt"),
    _phong("LightShader.txt", "Phong.txt")
{}

Shader& ShaderInstances::blinn()
{
    return instance()._blinn;
}

Shader& ShaderInstances::constant()
{
    return instance()._constant;
}

Shader& ShaderInstances::lambert()
{
    return instance()._lambert;
}

Shader& ShaderInstances::phong()
{
    return instance()._phong;
}
