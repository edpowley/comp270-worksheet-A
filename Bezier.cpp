#include "stdafx.h"
#include "Bezier.h"

Bezier::Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3)
{
	m_points[0] = p0;
	m_points[1] = p1;
	m_points[2] = p2;
	m_points[3] = p3;
}

void Bezier::draw(SDL_Renderer *renderer) const
{
	// TODO

	float lastX = m_points[0].getX(), lastY = m_points[0].getY();

	for (int i = 1; i <= 20; i++)
	{
		float t = (float)i / 20.0f;
		float s = 1 - t;

		float x = s * s*s*m_points[0].getX() + 3 * s*s*t*m_points[1].getX() + 3 * s*t*t*m_points[2].getX() + t * t*t*m_points[3].getX();
		float y = s * s*s*m_points[0].getY() + 3 * s*s*t*m_points[1].getY() + 3 * s*t*t*m_points[2].getY() + t * t*t*m_points[3].getY();
		SDL_RenderDrawLineF(renderer, lastX, lastY, x, y);
		lastX = x;
		lastY = y;
	}
}
