
#include <cmath>
#include "Vertices.h"

// Function to subtract two Point3D values
Point3D subtract(const Point3D & p1, const Point3D & p2)
{
    Point3D result;
    result.x = p1.x - p2.x;
    result.y = p1.y - p2.y;
    result.z = p1.z - p2.z;
    return result;
}

Point3D cross(const Point3D& a, const Point3D& b)
{
    Point3D result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

Point3D normalize(const Point3D& v)
{
    float magnitude = std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    Point3D normalized;
    normalized.x = v.x / magnitude;
    normalized.y = v.y / magnitude;
    normalized.z = v.z / magnitude;
    return normalized;
}

Point3D getNormal(const Point3D& x0, const Point3D& x1, const Point3D& x2)
{
    Point3D v0 = subtract(x0, x2);
    Point3D v1 = subtract(x1, x2);
    Point3D n = cross(v0, v1);
    return normalize(n);
}