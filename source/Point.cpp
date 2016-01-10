#include "Point.h"

Point * Point::create()
{
	return create(0);
}

Point * Point::create(const float n)
{
	return create(n, 1.0);
}

Point * Point::create(const float n, const float w)
{
	return create(n, n, n, w);
}

Point * Point::create(const float x, const float y, const float z)
{
	return create(x, y, z, 1.0);
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
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
	return true;
}

const Point & Point::operator=(const Point & operand)
{
	this->x = operand.x;
	this->y = operand.y;
	this->z = operand.y;
	this->w = operand.w;

	return * this;
	// TODO: insert return statement here
}

const Point & Point::operator+(const Vec4 & operand)
{

	this->x += operand.x;
	this->y += operand.y;
	this->z += operand.z;

	return *this;
	// TODO: insert return statement here
}
