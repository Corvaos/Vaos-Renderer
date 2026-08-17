#include "vaos/renderer/Shader.h"

using namespace vaos::renderer;

void Shader::setAssetLocationPrefix(std::string a) { prefix = a; }

void Shader::checkShaderCompile(unsigned int vertexShader) {
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }
}

std::string Shader::readShader(std::string filePath) {
  std::ifstream inputStream = std::ifstream(filePath);

  if (!inputStream.is_open()) {
    std::cerr << "Shader file not found" << std::endl;
    return "";
  }

  std::stringstream buffer;
  buffer << inputStream.rdbuf();
  return buffer.str();
}

unsigned int Shader::compileShader(std::string vertexFilePath,
                                   std::string fragmentFilePath) {

  vertexFilePath = prefix + vertexFilePath;
  fragmentFilePath = prefix + fragmentFilePath;
  // Shader
  const std::string vertexSourceString = readShader(vertexFilePath);
  const char *vertexShaderLocation = vertexSourceString.c_str();
  const unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderLocation, NULL);
  glCompileShader(vertexShader);

  checkShaderCompile(vertexShader);

  const std::string fragSourceString = readShader(fragmentFilePath);
  const char *fragmentShaderLocation = fragSourceString.c_str();
  const unsigned int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragShader, 1, &fragmentShaderLocation, NULL);
  glCompileShader(fragShader);

  checkShaderCompile(fragShader);

  unsigned int shaderProgram;
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragShader);
  glLinkProgram(shaderProgram);

  glDeleteShader(vertexShader);
  glDeleteShader(fragShader);

  shaderPrograms.push_back(shaderProgram);
  return shaderProgram;
}