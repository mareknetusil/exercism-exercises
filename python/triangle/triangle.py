import typing as tp


def equilateral(sides: tp.Sequence[float]) -> bool:
    return is_triangle(sides) and len(set(sides)) == 1


def isosceles(sides: tp.Sequence[float]) -> bool:
    return is_triangle(sides) and len(set(sides)) <= 2


def scalene(sides: tp.Sequence[float]) -> bool:
    return is_triangle(sides) and len(set(sides)) == 3


def is_triangle(sides: tp.Sequence[float]) -> bool:
    try:
        x, y, max_ = sorted(sides)
    except ValueError:
        return False
    return x + y > max_
