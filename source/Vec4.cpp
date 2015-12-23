#include "Vec4.h"

Vec4::Vec4() {

	Vec4(0.0, 0.0, 0.0);
}

Vec4::Vec4(const GLfloat x, const GLfloat y, const GLfloat z) {

	Vec4(x, y, z, 0.0);
}

Vec4::Vec4(const Vec4 & source) {

	Vec4(source.x, source.y, source.z, source.w);
}

Vec4::Vec4(const GLfloat x, const GLfloat y, const GLfloat z, const GLfloat w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

const GLfloat Vec4::dotProduct(const Vec4 & operand)
{
	return this->x * operand.x + this->y * operand.y + this->z * operand.z + this->w * operand.w;
}

const Vec4 Vec4::crossProduct(const Vec4 & operand)
{
	return Vec4(
			this->y * operand.z - this->z * operand.y,
			this->z * operand.x - this->x * operand.z,
			this->x * operand.y - this->y * operand.x
		);
}

Vec4 Vec4::operator*(const GLfloat operand)
{
	return Vec4(this->x * operand,
				this->y * operand,
				this->z * operand,
				this->w * operand);
}

