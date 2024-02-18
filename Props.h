
#pragma once

#ifndef PROPS_H
#define PROPS_H

#include <string>

#include "Mesh.h"
#include "Textures.h"

#include "Rock1.h"
#include "Rock2.h"
#include "Rock3.h"
#include "Rock4.h"
#include "Rock5.h"

#include "HexagonBase.h"
#include "HexagonBlock.h"
#include "HexagonOpenWall.h"
#include "HollowHexagonBase.h"
#include "HollowHexagon2.h"
#include "HexagonWalkPath.h"

#include "DeformedCube.h"

#include "StairsMiddle.h"
#include "StairsSide.h"

#include "WallLedge.h"

#include "Cloud1.h"
#include "Cloud2.h"
#include "Cloud3.h"

void createProp(Mesh& mesh, const std::string& textureFilename, float rot, float textureScale);

void hexagonBase(const std::string& textureFilename);
void hexagonBlock(const std::string& textureFilename);
void hexagonOpenWall(const std::string& textureFilename);
void hollowHexagon(const std::string& textureFilename);
void hollowHexagon2(const std::string& textureFilename);
void hexagonWalkPath(const std::string& textureFilename);

void deformedCube(const std::string& textureFilename);

void wallLedge(const std::string& textureFilename);

void cloud1(const std::string& textureFilename);
void cloud2(const std::string& textureFilename);
void cloud3(const std::string& textureFilename);

void stairs(float rot, int dir);

void stairsMiddle(const std::string& textureFilename);
void stairsSide(const std::string& textureFilename);

void rocks();

void rock1(const std::string& textureFilename, float textureScale);
void rock2(const std::string& textureFilename, float textureScale);
void rock3(const std::string& textureFilename, float textureScale);
void rock4(const std::string& textureFilename, float textureScale);
void rock5(const std::string& textureFilename, float textureScale);

#endif