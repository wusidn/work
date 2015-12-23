#pragma once
#ifndef __ENGINE_VEC4_H__
#define __ENGINE_VEC4_H__

#include <gl\glew.h>
#include "Object.h"

struct Vec4
{

public:

	GLfloat x, y, z, w;

	Vec4();
	Vec4(const GLfloat x, const GLfloat y, const GLfloat z);
	Vec4(const Vec4 & source);

	Vec4(const GLfloat x, const GLfloat y, const GLfloat z, const GLfloat w);

	const GLfloat dotProduct(const Vec4 & operand);
	const Vec4 crossProduct(const Vec4 & operand);

	virtual Vec4 operator*(const GLfloat operand);
	
};

#endif //__ENGINE_VEC4_H__