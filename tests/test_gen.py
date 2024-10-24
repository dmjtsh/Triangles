import random

def generate_triangles(num_triangles):
    triangles = []
    for _ in range(num_triangles):
        triangle = [
            (random.randint(-10000, 10000), random.randint(-10000, 10000), random.randint(-10000, 10000)),
            (random.randint(-10000, 10000), random.randint(-10000, 10000), random.randint(-10000, 10000)),
            (random.randint(-10000, 10000), random.randint(-10000, 10000), random.randint(-10000, 10000))
        ]
        triangles.append(triangle)

    return triangles

def save_triangles_to_file(triangles, filename):
    with open(filename, 'w') as file:
        file.write(f"{len(triangles)}\n")
        for triangle in triangles:
            points_line = ' '.join(f"{point[0]} {point[1]} {point[2]}" for point in triangle)
            file.write(f"{points_line}\n")

num_triangles = int(input("Enter triangles num: "))
triangles = generate_triangles(num_triangles)

filename = "test3.txt"
save_triangles_to_file(triangles, filename)

print(f"Test saved in file: {filename}")
