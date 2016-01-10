#include "Point.h"

Point::Point()
{
	Point(0.0f);
}

Point::Point(const float a)
{
	Point(a, 1.0f);
}

Point::Point(const float a, const float w)
{
	Point(a, a, a, w);
}

Point::Point(const float x, const float y, const float z)
{
	Point(x, y, z, 1.0f);
}

Point::Point(const float x, const float y, const float z, const float w)
{
	stack_init(x, y, z, w);
}

Point * Point::create()
{
	return create(0.0f);
}

Point * Point::create(const float a)
{
	return create(a, 1.0f);
}

Point * Point::create(const float a, const float w)
{
	return create(a, a, a, w);
}

Point * Point::create(const float x, const float y, const float z)
{
	return create(x, y, z, 1.0f);
}

Point * Point::create(const float x, const float y, const float z, const float w)
{
	Point * result = new Point();
	if (!result->init(x, y, z, w)) {
		delete result;
		result = nullptr;
	}
	return result;
}

const bool Point::init(const float x, const float y, const float z, const float w)
{
	if (!Object::init()) {
		return false;
	}
	stack_init(x, y, z, w);
	return true;
}

const void Point::stack_init(const float w, const float x, const float y, const float z)
{
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
}

const Point & Point::operator=(const Point & operand)
{
	this->x = operand.x;
	this->y = operand.y;
	this->z = operand.y;
	this->w = operand.w;

	return * this;
}

const Point & Point::operator+(const Vec4 & operand)
{

	this->x += operand.x;
	this->y += operand.y;
	this->z += operand.z;

	return *this;
}
