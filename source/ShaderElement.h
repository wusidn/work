#pragma once
#ifndef __SHADER_ELEMENT_H__
#define __SHADER_ELEMENT_H__

#include "EngineObject.h"


#include <string>
#include <gl\glew.h>
#include <gl\freeglut.h>
#include <fstream>

using namespace std;

class ShaderElement : public EngineObject
{
public:

	static ShaderElement * create();
	static ShaderElement * createWithShaderCode(const GLuint shaderType, const string & code);

	static const string getShaderSource(const string & path);

	const bool init();
	const bool initWithShaderCode(const GLuint shaderType, const string & code);
	const bool compile(void) const;
	const bool _compile_pass(void) const;
	const string getError(void) const;

	const GLuint get_shaderId(void) const;

	~ShaderElement();

private:
	GLuint _shaderId;
};

#endif //__SHADER_ELEMENT_H__
