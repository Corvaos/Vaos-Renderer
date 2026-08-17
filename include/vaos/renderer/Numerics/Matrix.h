#pragma once

#include "vaos/renderer/Numerics/Vector3.h"
#include <array>
#include <cmath>
#include <cstddef>

namespace vaos::numerics {

template <typename T, std::size_t Rows, std::size_t Columns> struct Matrix {
  std::array<T, Rows * Columns> data;

  // -------------------- IDENTIY MATRIX --------------------
  Matrix() {
    data.fill(0);
    for (int i = 0; i < Rows; i++) {
      data[i * Columns + i] = 1;
    }
  }

  // -------------------- RESULT OPERATORS --------------------
  [[nodiscard]] Matrix operator+(const Matrix &a) const {
    Matrix<T, Rows, Columns> output;

    for (int i = 0; i < Rows * Columns; i++) {
      output.data[i] = data[i] + a.data[i];
    }

    return output;
  }

  [[nodiscard]] Matrix operator-(const Matrix &a) const {
    Matrix<T, Rows, Columns> output;

    for (int i = 0; i < Rows * Columns; i++) {
      output.data[i] = data[i] - a.data[i];
    }

    return output;
  }

  [[nodiscard]] Matrix operator*(const float &a) const {
    Matrix<T, Rows, Columns> output;

    for (int i = 0; i < Rows * Columns; i++) {
      output.data[i] = data[i] * a;
    }

    return output;
  }

  [[nodiscard]] Matrix operator/(const float &a) const {
    Matrix<T, Rows, Columns> output;

    for (int i = 0; i < Rows * Columns; i++) {
      output.data[i] = data[i] / a;
    }

    return output;
  }

  // -------------------- IMMEDIATE OPERATORS --------------------
  void operator+=(const Matrix &a) {
    for (int i = 0; i < Rows * Columns; i++) {
      data[i] += a.data[i];
    }
  }

  void operator-=(const Matrix &a) {
    for (int i = 0; i < Rows * Columns; i++) {
      data[i] -= a.data[i];
    }
  }

  void operator*=(const float &a) {
    for (int i = 0; i < Rows * Columns; i++) {
      data[i] *= a;
    }
  }

  void operator/=(const float &a) {
    for (int i = 0; i < Rows * Columns; i++) {
      data[i] /= a;
    }
  }

  // -------------------- MATRIX MULTIPLICATION --------------------
  template <size_t z>
  Matrix<T, Rows, z> operator*(const Matrix<T, Columns, z> &a) {
    Matrix<T, Rows, z> output;

    for (int row = 0; row < Rows; row++) {
      for (int column = 0; column < z; column++) {
        float sum = 0;

        for (size_t i = 0; i < Columns; i++) {
          sum += data[row + i * Rows] * a.data[i + column * Columns];
        }

        output.data[row + column * Rows] = sum;
      }
    }

    return output;
  }

  // -------------------- TRANSFORMS --------------------
  static Matrix<float, 4, 4> scale(const Vector3 &a) {
    Matrix<float, 4, 4> output;
    output.data[0] = a.x;
    output.data[5] = a.y;
    output.data[10] = a.z;
    return output;
  }

  static Matrix<float, 4, 4> rotateX(const Vector3 &a) {
    Matrix<float, 4, 4> output;

    const float c = std::cos(a.x);
    const float s = std::sin(a.x);
    output.data[5] *= c;
    output.data[6] *= s;
    output.data[9] *= -s;
    output.data[10] *= c;

    return output;
  }

  static Matrix<float, 4, 4> rotateY(const Vector3 &a) {
    Matrix<float, 4, 4> output;

    const float c = std::cos(a.y);
    const float s = std::sin(a.y);
    output.data[0] = c;
    output.data[2] = -s;
    output.data[8] = s;
    output.data[10] = c;

    return output;
  }

  static Matrix<float, 4, 4> rotateZ(const Vector3 &a) {
    Matrix<float, 4, 4> output;

    const float c = std::cos(a.z);
    const float s = std::sin(a.z);
    output.data[0] = c;
    output.data[1] = s;
    output.data[4] = -s;
    output.data[5] = c;

    return output;
  }

  static Matrix<float, 4, 4> rotate(const Vector3 &a) {
    return rotateZ(a) * rotateY(a) * rotateX(a);
  }

  static Matrix<float, 4, 4> translate(const Vector3 &a) {
    Matrix<float, 4, 4> output;
    output.data[12] = a.x;
    output.data[13] = a.y;
    output.data[14] = a.z;
    return output;
  }
};

using Matrix2 = Matrix<float, 2, 2>;
using Matrix3 = Matrix<float, 3, 3>;
using Matrix4 = Matrix<float, 4, 4>;

} // namespace vaos::numerics