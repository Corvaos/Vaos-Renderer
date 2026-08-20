#include "vaos/renderer/Mesh/MeshFactory.h"
#include "vaos/renderer/Numerics/Vector3.h"
#include <exception>

using Mesh = vaos::renderer::Mesh;
using MeshFactory = vaos::renderer::MeshFactory;

// ------------------ FETCH MESH ------------------
Mesh& MeshFactory::getMesh(const std::string& meshName)
{
  try
  {
    return meshes.at(meshName);
  }
  catch (std::exception& e)
  {
    std::cerr << "MESH NOT FOUND: " << e.what() << std::endl;
    exit(-1);
  }
}

// ------------------ BASIC POLYGONS ------------------
Mesh MeshFactory::generateSquare()
{
  if (!meshes.contains("square"))
  {
    const std::vector<vaos::numerics::Vector3> vertices = {
      vaos::numerics::Vector3(1, 1, 0), vaos::numerics::Vector3(-1, 1, 0),
      vaos::numerics::Vector3(-1, -1, 0), vaos::numerics::Vector3(1, -1, 0)
    };
    const std::vector<unsigned int> indices = {0, 1, 2, 0, 2, 3};

    meshes.emplace("square", Mesh(vertices, indices));
  }
  return meshes.at("square");
};

Mesh MeshFactory::generateTriangle()
{
  if (!meshes.contains("triangle"))
  {
    const std::vector<vaos::numerics::Vector3> vertices = {
      vaos::numerics::Vector3(0, SQRT3 / 3, 0),
      vaos::numerics::Vector3(-SQRT3 / 2, -SQRT3 / 6, 0),
      vaos::numerics::Vector3(SQRT3 / 2, -SQRT3 / 6, 0)
    };
    const std::vector<unsigned int> indices = {0, 1, 2};

    meshes.emplace("triangle", Mesh(vertices, indices));
  }
  return meshes.at("triangle");
}

// ------------------ CIRCLE ------------------
Mesh MeshFactory::generateCircle(const int resolution, const bool cache = true)
{
  std::string reference = "circle" + std::to_string(resolution);
  if (meshes.contains(reference))
  {
    return meshes.at(reference);
  }

  std::vector<vaos::numerics::Vector3> vertices = {vaos::numerics::Vector3(0, 0, 0)};
  const double step = 6.283185307 / resolution;

  for (int i = 0; i < resolution; i++)
  {
    vertices.emplace_back(
      std::cos(step * i), // x
      std::sin(step * i), // y
      0);
  }

  std::vector<unsigned int> ebo;

  for (int i = 0; i < resolution - 1; i++)
  {
    ebo.push_back(0); // center
    ebo.push_back(i + 1); // current
    ebo.push_back((i + 1) % resolution + 1); // adjacent
  }

  ebo.push_back(0);
  ebo.push_back(resolution);
  ebo.push_back(1);

  const Mesh mesh = Mesh(vertices, ebo);
  if (cache)
  {
    meshes.emplace(reference, mesh);
  }

  return mesh;
}
