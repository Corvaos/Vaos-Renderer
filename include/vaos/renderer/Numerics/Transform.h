#pragma once

#include "vaos/renderer/Numerics/Matrix.h"
#include "vaos/renderer/Numerics/Vector3.h"

namespace vaos::numerics {
struct Transform {
  Vector3 translation;
  Vector3 rotation;
  Vector3 scale;

  Transform()
      : translation(Vector3(0, 0, 0)), rotation(Vector3(0, 0, 0)),
        scale(Vector3(1, 1, 1)) {}

  Transform(Vector3 translation, Vector3 rotation, Vector3 scale)
      : translation(translation), rotation(rotation), scale(scale) {}

  Transform operator+(const Transform &a) {
    return Transform(translation + a.translation, rotation + a.rotation,
                     scale + a.scale);
  }

  Transform operator-(const Transform &a) {
    return Transform(translation - a.translation, rotation - a.rotation,
                     scale - a.scale);
  }

  Transform operator*(const double &a) {
    return Transform(translation * a, rotation * a, scale * a);
  }

  Transform operator/(const double &a) {
    return Transform(translation / a, rotation / a, scale / a);
  }

  void operator+=(const Transform &a) {
    translation += a.translation;
    rotation += a.rotation;
    scale += a.scale;
  }

  void operator-=(const Transform &a) {
    translation -= a.translation;
    rotation -= a.rotation;
    scale -= a.scale;
  }

  void operator*=(const double &a) {
    translation *= a;
    rotation *= a;
    scale *= a;
  }

  void operator/=(const double &a) {
    translation /= a;
    rotation /= a;
    scale /= a;
  }

  Matrix4 matrix() const {
    return Matrix4::translate(translation)
         * Matrix4::rotate(rotation)
         * Matrix4::scale(scale);
}
};
} // namespace vaos::numerics