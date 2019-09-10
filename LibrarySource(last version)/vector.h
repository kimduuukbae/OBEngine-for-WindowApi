#pragma once

class Vector2D {
public:
	Vector2D(float _x, float _y);
	Vector2D() = default;
	Vector2D& normalize();

	Vector2D operator-(const Vector2D& rhs);
	Vector2D& operator=(const Vector2D& rhs);
	Vector2D operator+(const Vector2D& rhs);
	Vector2D& operator+=(const Vector2D& rhs);
	Vector2D operator*(float _scalar);

	float getX() const;
	float getY() const;
	float distance(const Vector2D& rhs);
private:
	float length();

	float x, y;
};