# Vaos Renderer v1

## Overview
Vaos Renderer is a basic C++ rendering framework built on top of OpenGL, meant to make initialization and management of basic shapes easier. It does so by caching standard meshes for repeated use, managing shaders, and keeping transforms to a user readable level.

## Capabilities
The Vaos Renderer is capable of:
### Primitive Shapes (Mesh)
* Triangle
* Square
* Circle (configurable resolution)
### Rendering
* User-defined Shaders
* Automated Transformations
### Window Management
* Window Management Abstraction

## Limitations
The Vaos Renderer (v1) is currently limited by the following:
* Three primitive shapes. 
* Only 2D rendering.
* Global rendering states, such as background color, cannot be changed. 

## Technologies
* C++ 20
* OpenGL
* GLFW
* GLAD
* CMake

## Future Developments
Planned Features include:
* 3D Rendering
* Additional Primitive Meshes
* Built-in Textures
* Lighting
* Camera
* Customization
* Refactoring of Numerics to the VaosNumerics library

## Design Goals
The Vaos Renderer is designed with the primary purpose of making development of my future projects more streamlined, so I can focus on the physics behind a simulation rather than the rendering architecture. Thus, the following design goals were pursued:
* Variable properties. Objects should be able to be transformed and rendered quickly.
* Abstraction. Management of objects should be simple and intuitive.
* Integration. This library should be able to be plugged into a project and be able to run various objects with various properties.