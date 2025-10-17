#pragma once
#include "../../src/config.h"

class Shader {
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    void use() const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;

};
