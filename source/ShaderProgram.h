#pragma once
#ifndef __SHADER_PROGRAM__
#define __SHADER_PROGRAM__

#include "Object.h"
#include "ShaderElement.h"
#include <list>
#include <string>

using namespace std;

//着色器程序  封装着色器的链接
class ShaderProgram : public Object
{
public:

	~ShaderProgram();

	//构造函数
	static ShaderProgram * create(void);
	static ShaderProgram * create(const list<ShaderElement *> & shaderElements);

	//初始化函数
	const bool init(void);
	bool initWitchShaderElements(const list<ShaderElement *> & shaderElements) ;

	//加入一个着色器
	const bool attachShader(const ShaderElement & shaderElement) const;
	//
	const bool detachShader(const ShaderElement & shaderElement) const;


	//链接所有着色器
	const bool linkProgram(void) const;

	//获取着色器程序id
	const GLuint programId(void) const;
	
	//获取错误信息
	const string getError(void) const;

	//tool
	static const size_t TypeSize(const GLenum type);

private:
	GLuint _shaderProgramId;

	const bool _link_pass(void) const;
};

#endif //__SHADER_PROGRAM__
