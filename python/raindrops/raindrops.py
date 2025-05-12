def convert(number: int) -> str:
    sounds = {
        3: 'Pling',
        5: 'Plang',
        7: 'Plong'
    }
    response = ''.join(
        sound for divisor, sound in sounds.items()
        if number % divisor == 0
    )

    return response or str(number)
