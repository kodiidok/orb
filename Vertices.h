#pragma once

#ifndef VERTICES_H
#define VERTICES_H

struct Point2D
{
    float x, y;
};

struct Point3D
{
    float x, y, z;
};

struct Normal
{
    float x, y, z;
};

struct Vertex {
    Point3D p;
    Normal n;
};

struct Scale {
    float x, y, z;
};

struct Vector3 {
    float x, y, z;
};

Vector3 subtract(const Point3D& p1, const Point3D& p2);
Normal cross(const Vector3& a, const Vector3& b);
Normal normalize(const Normal& v);
Normal getNormal(const Point3D& x0, const Point3D& x1, const Point3D& x2);

#endif
