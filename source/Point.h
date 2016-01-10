#pragma once
#ifndef __POINT_H__
#define __POINT_H__

#include "Object.h"
#include "Vec4.h"
class Point : public Object
{
public :

	float w, x, y, z;

	Point();
	Point(const float a);
	Point(const float a, const float w);
	Point(const float x, const float y, const float z);
	Point(const float x, const float y, const float z, const float w);

	static Point * create();
	static Point * create(const float a);
	static Point * create(const float a, const float w);
	static Point * create(const float x, const float y, const float z);
	static Point * create(const float x, const float y, const float z, const float w);

	const bool init(const float w, const float x, const float y, const float z );
	const void stack_init(const float w, const float x, const float y, const float z);


	virtual const Point & operator=(const Point & operand);
	virtual const Point & operator+(const Vec4 & operand);

private:
	
};

#endif //__POINT_H__
