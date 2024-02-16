import numpy as np
import random

def generate_vertices(rows, columns, gap):
    vertices = []
    for i in range(rows):
        for j in range(columns):
            x = j * gap
            y = 0.0
            z = i * gap
            vertices.append((x, y, z))
    return vertices

def adjust_to_origin(vertices):
    centroid = np.mean(vertices, axis=0)
    centered_vertices = vertices - centroid
    return centered_vertices

def deform_vertices(vertices, deformation_factor, seed):
    random.seed(seed)
    deformed_vertices = []
    for vertex in vertices:
        x = vertex[0] + random.uniform(-deformation_factor, deformation_factor)
        y = vertex[1] + random.uniform(-deformation_factor, deformation_factor)
        z = vertex[2] + random.uniform(-deformation_factor, deformation_factor)
        deformed_vertices.append((x, y, z))
    return deformed_vertices

def generate_stacks(num_stacks, rows, columns, gap, vertical_gap, deformation_factor):
    all_vertices = []
    for i in range(num_stacks):
        vertices = generate_vertices(rows, columns, gap)
        adjusted_vertices = adjust_to_origin(vertices)
        deformed_vertices = deform_vertices(adjusted_vertices, deformation_factor, seed=i)
        deformed_vertices = np.array(deformed_vertices)  # Convert to NumPy array
        deformed_vertices[:, 1] += i * vertical_gap
        all_vertices.extend(deformed_vertices)
    return all_vertices

# Set parameters
num_stacks = 4
rows = 4
columns = 4
gap = 0.33
vertical_gap = 0.33
deformation_factor = 0.05

# Generate deformed vertices for all stacks
all_vertices = generate_stacks(num_stacks, rows, columns, gap, vertical_gap, deformation_factor)

# Print the deformed vertices
for i, vertex in enumerate(all_vertices):
    print(f"mesh.vertex({{ {vertex[0]:.2f}f, {vertex[1]:.2f}f, {vertex[2]:.2f}f }});")
