#pragma once

class Vector2
{
public:
	Vector2() : m_x(0), m_y(0) { }
	Vector2(float x, float y) : m_x(x), m_y(y) { }

	float getX() const { return m_x; }
	float getY() const { return m_y; }

	Vector2 operator+(const Vector2& other) const
	{
		return Vector2(m_x + other.m_x, m_y + other.m_y);
	}

	Vector2 operator-(const Vector2& other) const
	{
		return Vector2(m_x - other.m_x, m_y - other.m_y);
	}

	Vector2 operator*(float scalar) const
	{
		return Vector2(scalar * m_x, scalar * m_y);
	}

	float m_x, m_y;
};

inline Vector2 operator*(float scalar, const Vector2& vector)
{
	return Vector2(scalar * vector.m_x, scalar * vector.m_y);
}
