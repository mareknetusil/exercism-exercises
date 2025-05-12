import typing as tp


def classify(number: int) -> str:
    """ A perfect number equals the sum of its positive divisors.

    :param number: int a positive integer
    :return: str the classification of the input integer
    """
    if number < 1:
        raise ValueError('Classification is only possible for positive integers.')

    aliquot_sum = sum(factors(number))
    if aliquot_sum == number:
        return 'perfect'

    if aliquot_sum > number:
        return 'abundant'

    return 'deficient'


def factors(number: int) -> tp.Iterator[int]:
    """
    Returns the factors of a number excluding the number itself.
    """
    return (
        x for x in range(1, number // 2 + 1)
        if number % x == 0
    )
