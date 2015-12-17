#pragma once
#ifndef __SHADER_ELEMENT_H__
#define __SHADER_ELEMENT_H__

#include "Object.h"


#include <string>
#include <gl\glew.h>
#include <gl\freeglut.h>
#include <fstream>

using namespace std;

//着色器对象，封装着色器的编译过程
class ShaderElement : public Object
{
public:

	//构造函数
	static ShaderElement * create();
	static ShaderElement * createWithShaderCode(const GLuint shaderType, const string & code);

	//初始化函数
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
