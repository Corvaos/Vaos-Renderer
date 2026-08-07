#version 330 core

in vec3 localPosition;
out vec4 fragColor;

void main() {
    fragColor = vec4(abs(sin(localPosition.x)), abs(sin(localPosition.y)), abs(sin(localPosition.z)), 1.0);
}