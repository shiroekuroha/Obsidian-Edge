#ifndef GLOBAL_VECTOR2_H
#define GLOBAL_VECTOR2_H

#include <type_traits>

/**
 * 2 Points floating number data structure.
 */
class Vector2
{
public:
    Vector2();
    Vector2(double x, double y);

    Vector2(const Vector2 &);
    Vector2(Vector2 &&) noexcept = delete;

    ~Vector2() = default;

    Vector2 &operator=(const Vector2 &);
    Vector2 &operator=(Vector2 &&) noexcept = delete;

    bool operator==(const Vector2 &) const;

    Vector2 operator+(const Vector2 &) const;
    Vector2 &operator+=(const Vector2 &);

    Vector2 operator-(const Vector2 &) const;
    Vector2 &operator-=(const Vector2 &);


    operator std::string() const;

    template <typename T>
    Vector2 operator*(T other) const
    {
        static_assert(
            std::is_same<T, float>::value ||
                std::is_same<T, double>::value ||
                std::is_same<T, short>::value ||
                std::is_same<T, int>::value ||
                std::is_same<T, long>::value,
            "Template type must be float, double, short, int or long");

        return Vector2(x * other, y * other);
    }

    template <typename T>
    Vector2 &operator*=(T other)
    {
        static_assert(
            std::is_same<T, float>::value ||
                std::is_same<T, double>::value ||
                std::is_same<T, short>::value ||
                std::is_same<T, int>::value ||
                std::is_same<T, long>::value,
            "Template type must be float, double, short, int or long");

        x *= other;
        y *= other;

        return *this;
    }

    double x = 0;
    double y = 0;
};

#endif
