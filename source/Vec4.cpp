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

const float Vec4::dot(const Vec4 & operand)
{
	return this->x * operand.x + this->y * operand.y + this->z * operand.z + this->w * operand.w;
}

const Vec4 Vec4::cross(const Vec4 & operand)
{
	return Vec4(
			this->y * operand.z - this->z * operand.y,
			this->z * operand.x - this->x * operand.z,
			this->x * operand.y - this->y * operand.x
		);
}

Vec4 Vec4::operator*(const float operand)
{
	return Vec4(this->x * operand,
				this->y * operand,
				this->z * operand,
				this->w * operand);
}

