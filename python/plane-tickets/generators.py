"""Functions to automate Conda airlines ticketing system."""
import itertools as it
import typing as tp


def generate_seat_letters(number: int) -> tp.Iterator[str]:
    """Generate a series of letters for airline seats.

    :param number: int - total number of seat letters to be generated.
    :return: generator - generator that yields seat letters.

    Seat letters are generated from A to D.
    After D it should start again with A.

    Example: A, B, C, D

    """
    # a = ord('A')
    # return (chr(a + i % 4) for i in range(number))
    letters = it.cycle('ABCD')
    #NOTE: just returning islice is way better but the tests
    # require the return value to be a generator
    return (letter for letter in it.islice(letters, number))


def generate_seats(number: int) -> tp.Iterator[str]:
    """Generate a series of identifiers for airline seats.

    :param number: int - total number of seats to be generated.
    :return: generator - generator that yields seat numbers.

    A seat number consists of the row number and the seat letter.

    There is no row 13.
    Each row has 4 seats.

    Seats should be sorted from low to high.

    Example: 3C, 3D, 4A, 4B

    """
    seats_per_row = 4
    unlucky_row = 13
    row_nums = (1 + i // seats_per_row for i in range(number + 1))
    row_nums = (
        row if row < unlucky_row else row + 1
        for row in row_nums
    )  # skipping the unlucky row
    row_letter_pairs = zip(row_nums, generate_seat_letters(number))
    return (f'{row}{letter}' for row, letter in row_letter_pairs)


def assign_seats(passengers: list[str]) -> dict[str, str]:
    """Assign seats to passengers.

    :param passengers: list[str] - a list of strings containing names of passengers.
    :return: dict - with the names of the passengers as keys and seat numbers as values.

    Example output: {"Adele": "1A", "Björk": "1B"}

    """
    return dict(zip(passengers, generate_seats(len(passengers))))


def generate_codes(seat_numbers: list[str], flight_id: str) -> tp.Iterator[str]:
    """Generate codes for a ticket.

    :param seat_numbers: list[str] - list of seat numbers.
    :param flight_id: str - string containing the flight identifier.
    :return: generator - generator that yields 12 character long ticket codes.

    """
    return (f'{seat_num + flight_id:<012}' for seat_num in seat_numbers)
