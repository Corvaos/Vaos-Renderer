#pragma once

#include <cmath>

namespace vaos::numerics {

  struct Vector3 {
    double x;
    double y;
    double z;

    // -------------------- CONSTRUCTORS --------------------
    Vector3() = default;

    explicit Vector3(const double a) : x(a), y(a), z(a) {}

    Vector3(const double x, const double y, const double z) : x(x), y(y), z(z) {}

    // -------------------- RESULT OPERATORS --------------------
    Vector3 operator+(const Vector3 &a) const { return Vector3(x + a.x, y + a.y, x + a.z); }

    Vector3 operator-(const Vector3 &a) const { return Vector3(x - a.x, y - a.y, x - a.z); }

    Vector3 operator*(const double &a) const { return Vector3(x * a, y * a, z * a);}

    Vector3 operator/(const double &a) const { return Vector3(x / a, y / a, z / a); }

    // -------------------- IMMEDIATE OPERATORS --------------------
    void operator+=(const Vector3 &a) {
      x += a.x;
      y += a.y;
      z += a.z;
    }

    void operator-=(const Vector3 &a) {
      x -= a.x;
      y -= a.y;
      z -= a.z;
    }

    void operator*=(const double &a) {
      x *= a;
      y *= a;
      z *= a;
    }

    void operator/=(const double &a) {
      x /= a;
      y /= a;
      z /= a;
    }

    // -------------------- VECTOR OPERATIONS --------------------
    [[nodiscard]] double length() const
    {
      return std::sqrt(squareLength());
    }

    [[nodiscard]] double squareLength() const
    {
      return x * x + y * y + z * z;
    }
  };
} // namespace vaos::renderer