#pragma once
#include "Shader.h"
class ShaderInstances {
private:
	Shader _blinn;
	Shader _constant;
	Shader _lambert;
	Shader _phong;
	Shader _terrain;
	Shader _skybox;
	Shader _phong_no_textures;

	static ShaderInstances* sInstance;
	static ShaderInstances& instance();

	ShaderInstances();
public:
	static Shader& blinn();
	static Shader& constant();
	static Shader& lambert();
	static Shader& phong();
	static Shader& skybox();
	static Shader& terrain();
	static Shader& phong_no_textures();
};