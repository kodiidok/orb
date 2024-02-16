
#pragma once

#ifndef PROPS_H
#define PROPS_H

#include <string>
#include "Mesh.h"
#include "Textures.h"

void createProp(Mesh& mesh, const std::string& textureFilename);
void rock1(const std::string& textureFilename);
void rock2(const std::string& textureFilename);
void rock3(const std::string& textureFilename);
void rock4(const std::string& textureFilename);
void rock5(const std::string& textureFilename);

#endif