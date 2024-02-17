import math
import random

def generate_hexagon_vertices(radius, deformation_factor=0.05, seed=None):
    random.seed(seed)
    vertices = []
    for i in range(4):
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
        radius = base_radius * scale[i]
        hexagon = generate_hexagon_vertices(radius, deformation_factor, seed + i)
        
        # Adjust y-coordinate for each vertex
        hexagon = [(x, y + total_height, z) for x, y, z in hexagon]
        
        hexagon_sets.append(hexagon)
        total_height += gaps[i]
    return hexagon_sets

# Set parameters
num_hexagons = 4
base_radius = 1.0
scale = [1.0, 0.45, 1.0, 0.45]
gaps = [0.0, 1.1, 0.02, 0.87]
deformation_factor = 0.05
seed_value = 29

# Generate stacked hexagons
hexagon_sets = generate_stacked_hexagons(num_hexagons, base_radius, gaps, deformation_factor, seed_value)

# Print vertices in the specified format
for i, hexagon_vertices in enumerate(hexagon_sets):
    for vertex in hexagon_vertices:
        print(f"mesh.vertex({{ {vertex[0]:.3f}f, {vertex[1]:.3f}f, {vertex[2]:.3f}f }});")
