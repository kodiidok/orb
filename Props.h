
#pragma once

#ifndef PROPS_H
#define PROPS_H

#include <string>
#include "Mesh.h"
#include "Textures.h"

void createProp(Mesh& mesh, const std::string& textureFilename, float rot);

void hexagonBase(const std::string& textureFilename);
void hexagonOpenWall(const std::string& textureFilename);
void hollowHexagon(const std::string& textureFilename);

void deformedCube(const std::string& textureFilename);

void wallLedge(const std::string& textureFilename);

void stairs();

void stairsMiddle(const std::string& textureFilename);
void stairsSide(const std::string& textureFilename);

void rocks();

void rock1(const std::string& textureFilename);
void rock2(const std::string& textureFilename);
void rock3(const std::string& textureFilename);
void rock4(const std::string& textureFilename);
void rock5(const std::string& textureFilename);

#endif