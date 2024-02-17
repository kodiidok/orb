def add_one_to_mesh_faces(mesh_faces):
    return [
        [{vertex + 1 for vertex in face} for face in mesh_faces]
    ]

# Original mesh faces
original_faces = [
    {0, 9, 10, 1},
    {1, 10, 11, 2},
    {2, 11, 12, 3},
    {3, 12, 13, 4},
    {4, 13, 14, 5},
    {5, 14, 15, 6},
    {6, 15, 16, 7},
    {7, 16, 17, 8},
]

# Iterate 5 times, adding 1 to all elements each time
for _ in range(5):
    original_faces = add_one_to_mesh_faces(original_faces)

# Print the resulting mesh faces
for face in original_faces[0]:
    print(f"mesh.face({{ {', '.join(map(str, face))} }});")
