import time
import typing as tp


def is_armstrong_number(number: int) -> bool:
    start = time.perf_counter()
    digits = list(split_to_digits(number))
    count = len(digits)
    end = time.perf_counter()
    print(f'elapsed: {end - start}')
    return number == sum(d**count for d in digits)


def split_to_digits(number: int) -> tp.Iterator[int]:
    while number:
        yield number % 10
        number = number // 10
