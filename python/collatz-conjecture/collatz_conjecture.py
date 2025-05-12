import typing as tp


def steps(number: int) -> int:
    if number <= 0:
        raise ValueError('Only positive integers are allowed')

    return sum(1 for _ in collatz_sequence(number))


def collatz_sequence(number: int) -> tp.Iterator[int]:
    while True:
        if number == 1:
            return
        number = collatz_step(number)
        yield number


def collatz_step(number: int) -> int:
    if number % 2 == 0:
        return number // 2

    return 3 * number + 1
