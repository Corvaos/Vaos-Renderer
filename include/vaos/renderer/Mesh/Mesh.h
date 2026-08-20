#pragma once

#include <vector>

#include "vaos/renderer/Numerics/Vector3.h"
#include "vaos/renderer/GLFWContext.h"

namespace vaos::renderer {

class Mesh {
public:
  GLuint vao{}, vbo{}, ebo{};
  GLsizei indexCount{};

  Mesh(const std::vector<vaos::numerics::Vector3> &inputVector3s,
       const std::vector<unsigned int> &inputEBO) {
    indexCount = static_cast<GLsizei>(inputEBO.size());

    // GENERATE VARIABLE VALUES
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    // CREATES CONSTRUCTION CONSISTENCY
    glBindVertexArray(vao);

    // SET VERTICES
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vaos::numerics::Vector3) * inputVector3s.size(),
                 inputVector3s.data(), GL_STATIC_DRAW);

    // SET INDICES
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 sizeof(unsigned int) * inputEBO.size(), inputEBO.data(),
                 GL_STATIC_DRAW);

    // GIVE OPENGL INTERPRETATION
    glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 3 * sizeof(double),
                          static_cast<void*>(nullptr));
    glEnableVertexAttribArray(0);

    // Prevent overwriting future meshes
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }
};

} // namespace vaos::renderer