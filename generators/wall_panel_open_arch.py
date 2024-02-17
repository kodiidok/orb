import math

def wall_panel_open_arch(w, h, cx, cy, cz, radius, segments):
    sc = semi_circle(cx, cy, cz, radius, segments)

    # Add an element to the beginning
    sc.insert(0, [sc[0][0], -h, cz])

    # Add an element to the end
    sc.append([sc[-1][0], -h, cz])

    result = []

    changer = len(sc) // 4

    offsetx = (radius + w) / changer
    offsetyu = -h
    offsetyd = 0.0

    for i in range(len(sc)):
        x, y, z = sc[i]

        result.append([x, y, z])

        if i <= changer + 1:
            result.append([radius + w, cy + offsetyu, z])
            if i == 0:
                offsetyu += 2 * (h / changer)
            else:
                offsetyu += h / changer
        elif i < 3 * changer + 1:
            result.append([radius + w - offsetx, h, z])
            offsetx += (w + radius) / changer
        else:
            result.append([-(radius + w), h - offsetyd, z])
            if i == len(sc) - 2:
                offsetyd += 2 * (h / changer)
            else:
                offsetyd += h / changer

    return result

def semi_circle(centerx, centery, z, radius, segments):
    v = []

    for i in range(1 + (segments // 2)):
        theta = 2.0 * math.pi * float(i) / float(segments)  # Angle for each segment
        x = centerx + radius * math.cos(theta)
        y = centery + radius * math.sin(theta)
        p = [x, y, z]
        v.append(p)

    return v

w = 0.5
h = 2.0
cx = 0.0
cy = 0.0
cz = 0.0
radius = 1.0
segments = 16

result = wall_panel_open_arch(w, h, cx, cy, cz, radius, segments)
for vertex in result:
    print(f"mesh.vertex({{ {vertex[0]:.3f}f, {vertex[1]:.3f}f, {vertex[2]:.3f}f }});")
