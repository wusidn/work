#include "ShaderElement.h"
#include <iostream>
#include <fstream>


ShaderElement * ShaderElement::create()
{
	ShaderElement * result = new ShaderElement();
	if (result && !result->init())
	{
		delete result;
		result = nullptr;
	}
	return result;
}

ShaderElement * ShaderElement::createWithShaderCode(const GLuint type, const string & code)
{
	ShaderElement * result = new ShaderElement();

	if (result && !result->initWithShaderCode(type, code))
	{
		delete result;
		result = nullptr;
	}
	return result;
}


const bool ShaderElement::init()
{
	if (!Object::init())
	{
		return false;
	}
	return true;
}

const bool ShaderElement::initWithShaderCode(const GLuint type, const string & code)
{
	if (!Object::init())
	{
		return false;
	}
	if (code.length() < 1) 
	{
		return false;
	}
	if (glIsShader(_shaderId = glCreateShader(type)) != GL_TRUE)
	{
		return false;
	}
	const GLchar * source = code.c_str();
	glShaderSource(_shaderId, 1, &source, nullptr);

	return true;
}

const bool ShaderElement::compile(void) const
{
	glCompileShader(_shaderId);
	return _compile_pass();
}

const bool ShaderElement::_compile_pass(void) const
{
	if (glIsShader(_shaderId) != GL_TRUE)
	{
		return false;
	}

	GLint compiled = 0;
	glGetShaderiv(_shaderId, GL_COMPILE_STATUS, &compiled);

	return compiled == GL_TRUE;
}


const string ShaderElement::getError(void) const
{
	//shader对象不存在或已被删除
	if (glIsShader(_shaderId) != GL_TRUE)
	{
		return "ShaderElement Create failed Or Is Delegated";
	}

	GLint compiled = 0;
	glGetShaderiv(_shaderId, GL_COMPILE_STATUS, &compiled);

	//没有错误
	if (compiled == GL_TRUE)
	{
		return "Shader Success";
	}

	GLint infoLen;
	glGetShaderiv(_shaderId, GL_INFO_LOG_LENGTH, &infoLen);

	//找不到错误信息
	if (infoLen == 0)
	{
		return "Not Fined Error Info";
	}

	GLchar * buff = (GLchar *)malloc(infoLen);
	if (!buff)
	{
		return "Get Error Info Fail";
	}
	glGetShaderInfoLog(_shaderId, infoLen, nullptr, buff);

	string result(buff);
	free(buff);
	return result;
}

const GLuint ShaderElement::get_shaderId(void) const
{
	if (!_compile_pass()) {
		return 0;
	}
	return _shaderId;
}

ShaderElement::~ShaderElement()
{
	if (glIsShader(_shaderId) == GL_TRUE)
	{
		glDeleteShader(_shaderId);
	}
}