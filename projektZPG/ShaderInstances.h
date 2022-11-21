#pragma once
#include "Shader.h"
class ShaderInstances {
private:
	Shader _blinn;
	Shader _constant;
	Shader _lambert;
	Shader _phong;

	static ShaderInstances* sInstance;
	static ShaderInstances& instance();

	ShaderInstances();

public:
	static Shader& blinn();
	static Shader& constant();
	static Shader& lambert();
	static Shader& phong();
};