#pragma once
#ifndef __SHADER_PROGRAM__
#define __SHADER_PROGRAM__

#include "EngineObject.h"
#include "ShaderElement.h"
#include <list>
#include <string>

using namespace std;

class ShaderProgram : public EngineObject
{
public:

	~ShaderProgram();

	static ShaderProgram * create(void);
	static ShaderProgram * create(const list<ShaderElement *> & shaderElements);

	const bool init(void);
	bool initWitchShaderElements(const list<ShaderElement *> & shaderElements) ;

	const bool attachShader(const ShaderElement & shaderElement) const;
	const bool detachShader(const ShaderElement & shaderElement) const;

	const bool linkProgram(void) const;

	const GLuint programId(void) const;
		
	const string getError(void) const;

	const bool _link_pass(void) const;

	//tool
	static const size_t TypeSize(const GLenum type);

private:
	GLuint _shaderProgramId;
};

#endif //__SHADER_PROGRAM__
