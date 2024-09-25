#ifndef GLOBAL_Vector2I_H
#define GLOBAL_Vector2I_H

#include <type_traits>

/**
 * 2 Points integer number data structure.
 */
class Vector2i
{
public:
	Vector2i();
	Vector2i(long x = 0, long y = 0);

	Vector2i(const Vector2i &);
	Vector2i(Vector2i &&) noexcept = delete;

	~Vector2i() = default;

	Vector2i &operator=(const Vector2i &);
	Vector2i &operator=(Vector2i &&) noexcept = delete;

	bool operator==(const Vector2i &) const;

	Vector2i operator+(const Vector2i &) const;
	Vector2i &operator+=(const Vector2i &);

	Vector2i operator-(const Vector2i &) const;
	Vector2i &operator-=(const Vector2i &);

	operator std::string() const;

	template <typename T>
	Vector2i operator*(T other) const
	{
		static_assert(
			std::is_same<T, short>::value ||
				std::is_same<T, int>::value ||
				std::is_same<T, long>::value,
			"Template type must be short, int or long");

		return Vector2i(x * other, y * other);
	}

	template <typename T>
	Vector2i &operator*=(T other)
	{
		static_assert(
			std::is_same<T, short>::value ||
				std::is_same<T, int>::value ||
				std::is_same<T, long>::value,
			"Template type must be short, int or long");

		x *= other;
		y *= other;

		return *this;
	}

	long x = 0;
	long y = 0;
};

#endif