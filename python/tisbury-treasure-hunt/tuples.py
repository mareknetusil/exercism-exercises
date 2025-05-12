"""Functions to help Azara and Rui locate pirate treasure."""
import typing as tp

AzaraR = tuple[str, str]
RuiR = tuple[str, tuple[str, str], str]


def get_coordinate(record: AzaraR) -> str:
    """Return coordinate value from a tuple containing the treasure name, and treasure coordinate.

    :param record: tuple - with a (treasure, coordinate) pair.
    :return: str - the extracted map coordinate.
    """
    return record[1]


def convert_coordinate(coordinate: str) -> tuple[str, str]:
    """Split the given coordinate into tuple containing its individual components.
plit
    :param coordinate: str - a string map coordinate
    :return: tuple - the string coordinate split into its individual components.
    """
    return coordinate[0], coordinate[1]


def compare_records(azara_record: AzaraR, rui_record: RuiR) -> bool:
    """Compare two record types and determine if their coordinates match.

    :param azara_record: tuple - a (treasure, coordinate) pair.
    :param rui_record: tuple - a (location, tuple(coordinate_1, coordinate_2), quadrant) trio.
    :return: bool - do the coordinates match?
    """
    return convert_coordinate(azara_record[1]) == rui_record[1]


def create_record(
        azara_record: AzaraR, rui_record: RuiR
) -> tuple[str, str, str, tuple[str, str], str] | str:
    """Combine the two record types (if possible) and create a combined record group.

    :param azara_record: tuple - a (treasure, coordinate) pair.
    :param rui_record: tuple - a (location, coordinate, quadrant) trio.
    :return: tuple or str - the combined record (if compatible), or the string "not a match" (if incompatible).
    """
    if compare_records(azara_record, rui_record):
        #NOTE: Without the explicit listing of all items there is no
        # way of making the typer checker happy.
        return *azara_record, *rui_record  # type: ignore

    return 'not a match'


def clean_up(
        combined_record_group: tp.Sequence[tuple[str, str, str, tuple[str, str], str]]
) -> str:
    """Clean up a combined record group into a multi-line string of single records.

    :param combined_record_group: tuple - everything from both participants.
    :return: str - everything "cleaned", excess coordinates and information are removed.

    The return statement should be a multi-lined string with items separated by newlines.

    (see HINTS.md for an example).
    """
    cleaned_tuples = map(
        lambda big_t: (*big_t[:1], *big_t[2:]),
        combined_record_group
    )
    return ''.join(map(lambda r: f'{r}\n', cleaned_tuples))
