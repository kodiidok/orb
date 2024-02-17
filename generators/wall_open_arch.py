import math

def rotate_point_y(point, angle_degrees):
    x, z = point[0], point[2]
    angle_radians = math.radians(angle_degrees)
    new_x = x * math.cos(angle_radians) - z * math.sin(angle_radians)
    new_z = x * math.sin(angle_radians) + z * math.cos(angle_radians)
    return [new_x, point[1], new_z]

def semi_circle(cx, cy, cz, radius, segments):
    v = []

    offset = 2 * radius

    for i in range(segments + 1):
        theta = math.pi * float(i) / float(segments)  # Angle for each segment
        x = radius * math.cos(theta)
        y = radius * math.sin(theta)
        p = [x + cx, y + cy, cz]
        v.append(p)

    v.append([cx + offset, cy, cz])
    v.append([cx + offset, cy + radius, cz])
    v.append([cx + offset, cy + 2 * radius, cz])
    v.append([cx + offset / 2, cy + 2 * radius, cz])
    v.append([cx, cy + 2 * radius, cz])
    v.append([cx - offset / 2, cy + 2 * radius, cz])

    return v

def translate_point(point, translation):
    return [point[0] + translation[0], point[1] + translation[1], point[2] + translation[2]]

# Set parameters
radius = 0.4
hexRadius = 1.5
segments = 8
rotation_angle = -60.0

# Generate and arrange 6 semi-circles in a hexagonal pattern
for i in range(6):
    # Calculate the position of each semi-circle in the hexagonal pattern
    angle_offset = 60.0 * i
    translation_vector = [hexRadius * math.sin(math.radians(angle_offset)), 1.0, hexRadius * math.cos(math.radians(angle_offset))]
    
    # Generate semi-circle
    semi_circle_vertices = semi_circle(0.0, 0.0, 0.0, radius, segments)

    # Apply rotation
    rotated_vertices = [rotate_point_y(vertex, rotation_angle * i) for vertex in semi_circle_vertices]
    
    # Apply translation
    translated_vertices = [translate_point(vertex, translation_vector) for vertex in rotated_vertices]

    # Print vertices
    for vertex in translated_vertices:
        print(f"mesh.vertex({{ {vertex[0]:.3f}f, {vertex[1]:.3f}f, {vertex[2]:.3f}f }});")
