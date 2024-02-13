#pragma once

#ifndef CASTLE_H
#define CASTLE_H

void hexagon(float centerX, float centerZ, float sideLength);
void hexagonBlock(float centerX, float centerZ, float sideLength, float height, float innerRadius);
void arch(float centerX, float centerY, float width, float height);
void initRandomRotations(int numBlocks);
void closedTowerBlock();
void singleDoorTowerBlock();
void twoDoorTowerBlock();
void openTowerBlock();
void openedTowerWall(float radius, float centerX, float centerY, float width, float height, float thickness);
void openedTowerWallPanel(float centerX, float centerY, float openWidth, float openHeight, float thickness);
void tower1(float radius, float centerX, float centerY, float openWidth, float openHeight, float thickness);

#endif