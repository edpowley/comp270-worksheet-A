#include "stdafx.h"
#include "Bezier.h"

Bezier::Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3)
	: p0(p0), p1(p1), p2(p2), p3(p3)
{
}

Vector2 Bezier::getPoint(float t) const
{
	float s = 1 - t;

	return s * s*s*p0 + 3 * s*s*t*p1 + 3 * s*t*t*p2 + t * t*t*p3;
}

Vector2 Bezier::getTangent(float t) const
{
	float s = 1 - t;

	return 3 * s*s*(p1 - p0) + 6 * s*t*(p2 - p1) + 3 * t*t*(p3 - p2);
}

void Bezier::draw(SDL_Renderer *renderer) const
{
	Vector2 last = p0;

	for (int i = 1; i <= 20; i++)
	{
		float t = (float)i / 20.0f;
		Vector2 p = getPoint(t);

		SDL_RenderDrawLineF(renderer, last.x, last.y, p.x, p.y);
		last = p;
	}
}
