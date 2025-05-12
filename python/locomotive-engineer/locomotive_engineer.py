"""Functions which helps the locomotive engineer to keep track of the train."""
import typing as tp


def get_list_of_wagons(*ids: int) -> list[int]:
    """Return a list of wagons.

    :param: arbitrary number of wagons.
    :return: list - list of wagons.
    """
    return list(ids)


def fix_list_of_wagons(
        each_wagons_id: list[int],
        missing_wagons: list[int]
) -> list[int]:
    """Fix the list of wagons.

    :param each_wagons_id: list - the list of wagons.
    :param missing_wagons: list - the list of missing wagons.
    :return: list - list of wagons.
    """
    loco_indx = each_wagons_id.index(1)
    return [
        1,
        *missing_wagons,
        *each_wagons_id[loco_indx + 1:],
        *each_wagons_id[:loco_indx]
    ]


def add_missing_stops(
        route: dict[str, str],
        **stops: str
) -> dict[str, tp.Any]:
    """Add missing stops to route dict.

    :param route: dict - the dict of routing information.
    :param: arbitrary number of stops.
    :return: dict - updated route dictionary.
    """
    return {
        **route,
        'stops': list(stops.values())
    }


def extend_route_information(
        route: dict[str, tp.Any],
        more_route_information: dict[str, tp.Any]
) -> dict[str, tp.Any]:
    """Extend route information with more_route_information.

    :param route: dict - the route information.
    :param more_route_information: dict -  extra route information.
    :return: dict - extended route information.
    """
    return route | more_route_information


def fix_wagon_depot(wagons_rows: list[list[tuple]]) -> list[list[tuple]]:
    """Fix the list of rows of wagons.

    :param wagons_rows: list[list[tuple]] - the list of rows of wagons.
    :return: list[list[tuple]] - list of rows of wagons.
    """
    return list(map(list, zip(*wagons_rows)))
