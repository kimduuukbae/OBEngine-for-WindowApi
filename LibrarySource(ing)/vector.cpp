#include "stdafx.h"
#include "vector.h"
#include <cmath>
Vector2D::Vector2D(float _x, float _y) : x(_x), y(_y) {}

Vector2D& Vector2D::normalize() {
	float len = length();

	x /= len;
	y /= len;
	return *this;
}
Vector2D Vector2D::operator-(const Vector2D& rhs) {
	return Vector2D( rhs.x - x, rhs.y - y );
}
Vector2D& Vector2D::operator=(const Vector2D& rhs) {
	x = rhs.x;
	y = rhs.y;
	return *this;
}
Vector2D Vector2D::operator+(const Vector2D& rhs) {
	return Vector2D( x + rhs.x, y + rhs.y );
}
Vector2D& Vector2D::operator+=(const Vector2D& rhs) {
	*this = *this + rhs;
	return *this;
}
float Vector2D::length() {
	return std::sqrtf(x * x + y * y);
}
float Vector2D::distance(const Vector2D& rhs) {
	return Vector2D(x - rhs.x, y - rhs.y).length();
}
Vector2D Vector2D::operator*(float _scalar) {
	return Vector2D( x *_scalar, y *_scalar );
}
float Vector2D::getX() const { return x; }
float Vector2D::getY() const { return y; }