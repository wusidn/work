#include "ShaderProgram.h"

ShaderProgram::~ShaderProgram()
{
	if (glIsProgram(_shaderProgramId) == GL_TRUE)
	{
		glDeleteProgram(_shaderProgramId);
	}
}

ShaderProgram * ShaderProgram::create(void)
{
	ShaderProgram * result = new ShaderProgram();
	if (result && !result->init())
	{
		delete result;
		result = nullptr;
	}
	return result;
}

ShaderProgram * ShaderProgram::create(const list<ShaderElement *> & shaderElements)
{
	ShaderProgram * result = new ShaderProgram();
	result->initWitchShaderElements(shaderElements);
	return result;
}

const bool ShaderProgram::init(void)
{
	if (!Object::init())
	{
		return false;
	}
	return glIsProgram(_shaderProgramId = glCreateProgram()) == GL_TRUE;
}

bool ShaderProgram::initWitchShaderElements(const list<ShaderElement *> & shaderElements)
{
	if (glIsProgram(_shaderProgramId = glCreateProgram()) != GL_TRUE)
	{
		return false;
	}

	for (auto item = shaderElements.begin(); item != shaderElements.end(); ++item)
	{
		if (!(*item)->_compile_pass())
		{
			continue;
		}
		attachShader(*(*item));
	}

	return true;
}

const bool ShaderProgram::attachShader(const ShaderElement & shaderElement) const
{
	const GLuint shaderId = shaderElement.get_shaderId();
	if (!shaderId)
	{
		return false;
	}
	glAttachShader(_shaderProgramId, shaderId);
	return true;
}

const bool ShaderProgram::detachShader(const ShaderElement & shaderElement) const
{
	const GLuint shaderElementId = shaderElement.get_shaderId();
	if (!shaderElementId)
	{
		return false;
	}
	glDetachShader(_shaderProgramId, shaderElementId);
	return true;
}

const bool ShaderProgram::linkProgram(void) const
{
	glLinkProgram(_shaderProgramId);
	return _link_pass();
}

const GLuint ShaderProgram::programId(void) const
{
	if (_link_pass())
		return _shaderProgramId;
	return 0;
}

const string ShaderProgram::getError(void) const
{
	if (glIsProgram(_shaderProgramId) != GL_TRUE)
	{
		return "Program Create Fail";
	}

	if (_link_pass())
	{
		return "";
	}
	GLint info_len = 0;
	glGetProgramiv(_shaderProgramId, GL_INFO_LOG_LENGTH, &info_len);
	if (info_len == 0)
	{
		return "Get ErrorInfo Fail";
	}
	GLchar * buff = (GLchar *)malloc(info_len);
	glGetProgramInfoLog(_shaderProgramId, info_len, nullptr, buff);

	string result(buff);
	free(buff);
	return result;
}

const bool ShaderProgram::_link_pass(void) const
{
	if (glIsProgram(_shaderProgramId) != GL_TRUE)
	{
		return false;
	}
	GLint linked;
	glGetProgramiv(_shaderProgramId, GL_LINK_STATUS, &linked);
	if (linked != GL_TRUE)
	{
		return false;
	}
	return true;
}

const size_t ShaderProgram::TypeSize(const GLenum type)
{
	size_t result;
#define CASE(Enum, Count, Type) case Enum : result = Count * sizeof(Type); break;

	switch (type) {
		CASE(GL_FLOAT, 1, GLfloat);
		CASE(GL_FLOAT_VEC2, 2, GLfloat);
		CASE(GL_FLOAT_VEC3, 3, GLfloat);
		CASE(GL_FLOAT_VEC4, 4, GLfloat);

		CASE(GL_INT, 1, GLint);
		CASE(GL_INT_VEC2, 2, GLint);
		CASE(GL_INT_VEC3, 3, GLint);
		CASE(GL_INT_VEC4, 4, GLint);

		CASE(GL_UNSIGNED_INT, 1, GLuint);
		CASE(GL_UNSIGNED_INT_VEC2, 2, GLuint);
		CASE(GL_UNSIGNED_INT_VEC3, 3, GLuint);
		CASE(GL_UNSIGNED_INT_VEC4, 4, GLuint);

		CASE(GL_BOOL, 1, GLboolean);
		CASE(GL_BOOL_VEC2, 1, GLboolean);
		CASE(GL_BOOL_VEC3, 1, GLboolean);
		CASE(GL_BOOL_VEC4, 1, GLboolean);

		CASE(GL_FLOAT_MAT2, 4, GLfloat);
		CASE(GL_FLOAT_MAT2x3, 6, GLfloat);
		CASE(GL_FLOAT_MAT2x4, 8, GLfloat);

		CASE(GL_FLOAT_MAT3, 9, GLfloat);
		CASE(GL_FLOAT_MAT3x2, 6, GLfloat);
		CASE(GL_FLOAT_MAT3x4, 12, GLfloat);

		CASE(GL_FLOAT_MAT4, 16, GLfloat);
		CASE(GL_FLOAT_MAT4x2, 8, GLfloat);
		CASE(GL_FLOAT_MAT4x3, 12, GLfloat);

#undef CASE

	default:
		result = -1;
		break;

	}

	return result;
}
