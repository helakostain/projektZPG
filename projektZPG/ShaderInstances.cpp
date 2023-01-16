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
    _blinn("light_no_textures.vert", "Blinn.frag"), 
    _constant("defaultvertex.vert", "defaultfragment.frag"),
    _lambert("light_no_textures.vert", "Lambert.frag"),
    _phong("light.vert", "phong.frag"),
    _skybox("skybox.vert", "skybox.frag"),
    _terrain("terrain.vert", "terrain.frag"),
    _phong_no_textures("light_no_textures.vert", "phong_no_textures.frag")
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

Shader& ShaderInstances::skybox()
{
    return instance()._skybox;
}

Shader& ShaderInstances::terrain()
{
    return instance()._terrain;
}

Shader& ShaderInstances::phong_no_textures()
{
    return instance()._phong_no_textures;
}
