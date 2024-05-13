#include "Utility/Vector2.h"

Vector2::Vector2()
	: x(0), y(0) {}

Vector2::Vector2(float x, float y)
	: x(x), y(y) {}

Vector2::Vector2(const Vector2 &other)
{
	*this = other;
}

Vector2 &Vector2::operator=(const Vector2 &other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}

	return *this;
}

bool Vector2::operator==(const Vector2 &other) const
{
	return x == other.x && y == other.y;
}

Vector2 Vector2::operator+(const Vector2 &other) const
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 &Vector2::operator+=(const Vector2 &other)
{
	x += other.x;
	y += other.y;

	return *this;
}

Vector2 Vector2::operator-(const Vector2 &other) const
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 &Vector2::operator-=(const Vector2 &other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}