#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
    unsigned int program;
    Shader(const char* vertexPath, const char* fragmentPath);
    void Use();
    void SetInt(const char* name, unsigned int number);
    void SetMat4(const char* name, const glm::mat4& mat);
private:
    void CheckErrors(unsigned int shader, std::string type);
};

#endif
