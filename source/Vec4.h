#pragma once
#ifndef __ENGINE_VEC4_H__
#define __ENGINE_VEC4_H__

#include "Object.h"

struct Vec4: public Object
{

public:

	float x, y, z, w;


	//static Vec4 * create();
	//static Vec4 * create(const float a);

	Vec4();
	Vec4(const float x, const float y, const float z);
	Vec4(const Vec4 & source);
	Vec4(const float x, const float y, const float z, const float w);


	//virtual const bool init(const float x, const float y, const float z, const float w);
	//const void stack_init(const float x, const float y, const float z, const float w);


	const float dot(const Vec4 & operand);
	const Vec4 cross(const Vec4 & operand);

	virtual Vec4 operator*(const float operand);


private:
	
};

#endif //__ENGINE_VEC4_H__