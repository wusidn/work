#include "Vec4.h"

Vec4::Vec4() {

	Vec4(0.0, 0.0, 0.0);
}

Vec4::Vec4(const float x, const float y, const float z) {

	Vec4(x, y, z, 0.0);
}

Vec4::Vec4(const Vec4 & source) {

	Vec4(source.x, source.y, source.z, source.w);
}

Vec4::Vec4(const float x, const float y, const float z, const float w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vec4 Vec4::operator*(const float operand)
{
	return Vec4(this->x * operand,
				this->y * operand,
				this->z * operand,
				this->w * operand);
}

float Vec4::operator*(const Vec4 & operand)
{
	return this->x * operand.x + this->y * operand.y + this->z * operand.z + this->w * operand.w;
}
