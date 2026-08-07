#pragma once

#include "Mesh.h"

#include <map>
#include <cmath> // SIN/COS
#include <string>

namespace vaos::renderer {

class MeshFactory {
    static constexpr double SQRT2 = 1.4142135624;
    static constexpr double SQRT3 = 1.7320508076;
public:
    static Mesh generateSquare();
    static Mesh generateTriangle();
    static Mesh generateCircle(int resolution, bool cache);

    static inline std::map<std::string, Mesh> meshes = {};

    static Mesh getMesh(std::string);
};

}