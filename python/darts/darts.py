
TARGET_ZONES = [
    (1, 10),
    (5, 5),
    (10, 1)
]

TARGET_ZONES_2 = [
    (r**2, p) for r, p in TARGET_ZONES
]


def score(x: float, y: float) -> int:
    dist = eucl_norm_2(x, y)

    for radius, points in TARGET_ZONES_2:
        if dist <= radius:
            return points

    return 0


def eucl_norm_2(*xs: float) -> float:
    """
    Returns an Euclidean norm squared to avoid the expensive square root.
    """
    return sum(map(lambda x: x**2, xs))
