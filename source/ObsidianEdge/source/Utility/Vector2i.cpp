#include "Utility/Vector2i.h"

Vector2i::Vector2i()
	: x(0), y(0) {}

Vector2i::Vector2i(long x, long y)
	: x(x), y(y) {}

Vector2i::Vector2i(const Vector2i &other)
{
	*this = other;
}

Vector2i &Vector2i::operator=(const Vector2i &other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}

	return *this;
}

bool Vector2i::operator==(const Vector2i &other) const
{
	return x == other.x && y == other.y;
}

Vector2i Vector2i::operator+(const Vector2i &other) const
{
	return Vector2i(x + other.x, y + other.y);
}

Vector2i &Vector2i::operator+=(const Vector2i &other)
{
	x += other.x;
	y += other.y;

	return *this;
}

Vector2i Vector2i::operator-(const Vector2i &other) const
{
	return Vector2i(x - other.x, y - other.y);
}

Vector2i &Vector2i::operator-=(const Vector2i &other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}

Vector2i::operator std::string() const
{
	std::string str = "X: " + std::to_string(x) + ", Y: " + std::to_string(y);

	return str;
}