def square(number: int) -> int:
    if 0 < number < 65:
        return 2**(number - 1)

    raise ValueError('square must be between 1 and 64')


def total() -> int:
    """
    A naive approach (but utilizing the other function in the exercise):
    return sum(square(i) for i in range(1, 65))

    Faster solution that does not just return a constant value:
    $$\sum_{k=0}^n a^k = \frac{1 - a^{n + 1}}{1 - a}$$.
    For a = 2 and n = 64, that is
    $$\sum_{k=0}^63 2^k = \frac{1 - 2^64}{1 - 2} = 2^64 - 1$$.
    """
    return 2**64 - 1
