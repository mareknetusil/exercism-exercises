import string


def response(hey_bob: str) -> str:
    hey_bob = hey_bob.strip()
    is_shout = hey_bob.isupper()
    is_question = hey_bob.endswith('?')
    if not hey_bob:
        return 'Fine. Be that way!'

    if is_question and is_shout:
        return 'Calm down, I know what I\'m doing!'

    if is_question:
        return 'Sure.'

    if is_shout:
        return 'Whoa, chill out!'

    return 'Whatever.'
