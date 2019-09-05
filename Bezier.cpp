#include "stdafx.h"
#include "Bezier.h"

Bezier::Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3)
{
	m_points[0] = p0;
	m_points[1] = p1;
	m_points[2] = p2;
	m_points[3] = p3;
}

Vector2 Bezier::getPoint(float t) const
{
	float s = 1 - t;

	return s * s*s*m_points[0] + 3 * s*s*t*m_points[1] + 3 * s*t*t*m_points[2] + t * t*t*m_points[3];
}

Vector2 Bezier::getTangent(float t) const
{
	float s = 1 - t;

	return 3 * s*s*(m_points[1] - m_points[0]) + 6 * s*t*(m_points[2] - m_points[1]) + 3 * t*t*(m_points[3] - m_points[2]);
}

void Bezier::draw(SDL_Renderer *renderer) const
{
	Vector2 last = m_points[0];

	for (int i = 1; i <= 20; i++)
	{
		float t = (float)i / 20.0f;
		Vector2 p = getPoint(t);

		SDL_RenderDrawLineF(renderer, last.x, last.y, p.x, p.y);
		last = p;
	}
}
