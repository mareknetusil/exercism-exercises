"""Solution to Ellen's Alien Game exercise."""
import dataclasses as dc
import typing as tp


@dc.dataclass
class Alien:
    """Create an Alien object with location x_coordinate and y_coordinate.

    Attributes
    ----------
    (class)total_aliens_created: int
    x_coordinate: int - Position on the x-axis.
    y_coordinate: int - Position on the y-axis.
    health: int - Number of health points.

    Methods
    -------
    hit(): Decrement Alien health by one point.
    is_alive(): Return a boolean for if Alien is alive (if health is > 0).
    teleport(new_x_coordinate, new_y_coordinate): Move Alien object to new coordinates.
    collision_detection(other): Implementation TBD.
    """
    x_coordinate: int
    y_coordinate: int
    health: int = 3

    total_aliens_created: tp.ClassVar[int] = 0

    def __post_init__(self):
        Alien.total_aliens_created += 1

    def hit(self) -> None:
        self.health += -1

    def is_alive(self) -> bool:
        return self.health > 0

    def teleport(self, new_x: int, new_y: int) -> None:
        self.x_coordinate = new_x
        self.y_coordinate = new_y

    def collision_detection(self, other_object):
        """
        To be implemented.
        """


def new_aliens_collection(positions: list[tuple[int, int]]) -> list[Alien]:
    return [Alien(*pos) for pos in positions]
