#pragma once

class Vector2
{
public:
	Vector2() : x(0), y(0) { }
	Vector2(float x, float y) : x(x), y(y) { }

	Vector2 operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator-(const Vector2& other) const
	{
		return Vector2(x - other.x, y - other.y);
	}

	Vector2 operator*(float scalar) const
	{
		return Vector2(scalar * x, scalar * y);
	}

	float x, y;
};

inline Vector2 operator*(float scalar, const Vector2& vector)
{
	return Vector2(scalar * vector.x, scalar * vector.y);
}
