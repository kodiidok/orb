
#include "Textures.h"

// Definitions for the static members
std::unordered_map<std::string, std::string> Textures::textureFilePaths;
std::unordered_map<std::string, GLuint> Textures::textureMap;

// Load texture from file and return the texture ID
GLuint Textures::loadTexture(const std::string& textureName) {
    // Check if texture is already loaded
    auto it = textureMap.find(textureName);
    if (it != textureMap.end()) {
        return it->second;
    }

    // Check if the file path is available
    auto filePathIt = textureFilePaths.find(textureName);
    if (filePathIt == textureFilePaths.end()) {
        // Handle error - File path not found
        printf("File path not found: %s\n", SOIL_last_result());
        return 0;
    }

    // Load the texture
    GLuint textureID = SOIL_load_OGL_texture(
        filePathIt->second.c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );

    if (!textureID) {
        // Handle error - Texture loading failed
        printf("Texture loading failed: %s\n", SOIL_last_result());
        return 0;
    }

    // Save texture ID for future use
    textureMap[textureName] = textureID;

    return textureID;
}

// Set the file path for a texture
void Textures::setTextureFilePath(const std::string& textureName, const std::string& filePath) {
    textureFilePaths[textureName] = filePath;
}
