#pragma once

class Vector2
{
public:
	Vector2() : m_x(0), m_y(0) { }
	Vector2(float x, float y) : m_x(x), m_y(y) { }

	float getX() const { return m_x; }
	float getY() const { return m_y; }

private:
	float m_x, m_y;
};
