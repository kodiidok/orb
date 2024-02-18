
#include <cmath>
#include "Vertices.h"

// Function to subtract two Point3D values
Vector3 subtract(const Point3D & p1, const Point3D & p2)
{
    Vector3 result;
    result.x = p1.x - p2.x;
    result.y = p1.y - p2.y;
    result.z = p1.z - p2.z;
    return result;
}

Normal cross(const Vector3& a, const Vector3& b)
{
    Normal result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

Normal normalize(const Normal& v)
{
    float magnitude = std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    Normal normalized;
    normalized.x = v.x / magnitude;
    normalized.y = v.y / magnitude;
    normalized.z = v.z / magnitude;
    return normalized;
}

Normal getNormal(const Point3D& x0, const Point3D& x1, const Point3D& x2)
{
    Vector3 v0 = subtract(x0, x2);
    Vector3 v1 = subtract(x1, x2);
    Normal n = cross(v0, v1);
    return normalize(n);
}
