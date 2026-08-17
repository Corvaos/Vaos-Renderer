#pragma once

namespace vaos::numerics {

struct Vector3 {
  double x;
  double y;
  double z;

  Vector3() = default;

  Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

  // -------------------- RESULT OPERATORS --------------------
  Vector3 operator+(const Vector3 &a) const {
    return Vector3(x + a.x, y + a.y, x + a.z);
  }

  Vector3 operator-(const Vector3 &a) const {
    return Vector3(x - a.x, y - a.y, x - a.z);
  }

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
};
} // namespace vaos::renderer