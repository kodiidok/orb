import math
import random

def generate_hexagon_vertices(radius, deformation_factor=0.05, seed=None):
    random.seed(seed)
    vertices = []
    for i in range(6):
        angle_rad = math.radians(60 * i)
        x = round(radius * math.cos(angle_rad), 3) + random.uniform(-deformation_factor, deformation_factor)
        y = random.uniform(-deformation_factor, deformation_factor)
        z = round(radius * math.sin(angle_rad), 3) + random.uniform(-deformation_factor, deformation_factor)
        vertices.append((x, y, z))
    return vertices

def generate_stacked_hexagons(num_hexagons, base_radius, gaps, deformation_factor=0.05, seed=None):
    hexagon_sets = []
    total_height = 0.0
    for i in range(num_hexagons):
        radius = base_radius
        hexagon = generate_hexagon_vertices(radius, deformation_factor, seed + i)
        
        # Adjust y-coordinate for each vertex
        hexagon = [(x * scale[i], y + total_height, z * scale[i]) for x, y, z in hexagon]
        
        hexagon_sets.append(hexagon)
        total_height += gaps[i] * 1.2
    return hexagon_sets

# Set parameters
num_hexagons = 8
base_radius = 1.0
scale = [0.9, 1.0, 1.0, 0.97, 0.93, 0.97, 0.95, 0.1]
gaps = [0.15, 0.5, 0.15, 0.25, 0.15, 0.35, 0.1, 0.15]
deformation_factor = 0.02
seed_value = 35

# Generate stacked hexagons
hexagon_sets = generate_stacked_hexagons(num_hexagons, base_radius, gaps, deformation_factor, seed_value)

# Print vertices in the specified format
for i, hexagon_vertices in enumerate(hexagon_sets):
    for vertex in hexagon_vertices:
        print(f"mesh.vertex({{ {vertex[0]:.3f}f, {vertex[1]:.3f}f, {vertex[2]:.3f}f }});")
