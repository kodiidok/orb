
#pragma once

#include <string>
#include <GL/glut.h>
#include <SOIL2.h>
#include <unordered_map>

class Textures {
private:
    static std::unordered_map<std::string, std::string> textureFilePaths;
    static std::unordered_map<std::string, GLuint> textureMap;

public:
    static GLuint loadTexture(const std::string& textureName);
    static void setTextureFilePath(const std::string& textureName, const std::string& filePath);
};
