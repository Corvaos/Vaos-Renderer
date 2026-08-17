# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 4.2)
set(CMAKE_CXX_STANDARD 20)

project ("VaosRenderer" LANGUAGES CXX)

# Include sub-projects.

add_library(VaosRenderer
# -------------- DEBUG --------------
#        examples/Application.cpp

# -------------- NUMERICS --------------
        include/vaos/renderer/Numerics/Vector3.h
        include/vaos/renderer/Numerics/Matrix.h
        include/vaos/renderer/Numerics/Transform.h

# -------------- WINDOW --------------

        src/vaos/renderer/Window.cpp
        include/vaos/renderer/Window.h

# -------------- OBJECTS --------------

        include/vaos/renderer/Mesh/Mesh.h
        src/vaos/renderer/Mesh/MeshFactory.cpp
        include/vaos/renderer/Mesh/MeshFactory.h
        
        src/vaos/renderer/Shader.cpp
        include/vaos/renderer/Shader.h
        include/vaos/renderer/Material.h

        include/vaos/renderer/RenderObject.h

# -------------- SETUP --------------
        include/vaos/renderer/GLFWContext.h
        
)

add_library(VaosRenderer::VaosRenderer ALIAS VaosRenderer)

target_include_directories(VaosRenderer PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(VaosRenderer PUBLIC
        glfw
        glad::glad
)