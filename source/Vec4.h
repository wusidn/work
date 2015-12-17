#pragma once
#ifndef __ENGINE_VEC4_H__
#define __ENGINE_VEC4_H__
#include "Object.h"

class Vec4
{

public:

	float x, y, z, w;

	Vec4();
	Vec4(const float x, const float y, const float z);
	Vec4(const Vec4 & source);

	Vec4(const float x, const float y, const float z, const float w);

	virtual Vec4 operator*(const float operand);
	virtual float operator*(const Vec4 & operand);
	//virtual Vec4 operator(const Vec4 & operand);
	
};

#endif //__ENGINE_VEC4_H__