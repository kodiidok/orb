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

Point3D subtract(const Point3D& p1, const Point3D& p2);
Point3D cross(const Point3D& a, const Point3D& b);
Point3D normalize(const Point3D& v);
Point3D getNormal(const Point3D& x0, const Point3D& x1, const Point3D& x2);

#endif
