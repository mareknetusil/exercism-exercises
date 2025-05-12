"""Functions for creating, transforming, and adding prefixes to strings."""
import re


def add_prefix_un(word: str) -> str:
    """Take the given word and add the 'un' prefix.

    :param word: str - containing the root word.
    :return: str - of root word prepended with 'un'.
    """
    return 'un' + word


def make_word_groups(vocab_words: list[str]) -> str:
    """Transform a list containing a prefix and words into a string with the prefix followed by the words with prefix prepended.

    :param vocab_words: list - of vocabulary words with prefix in first index.
    :return: str - of prefix followed by vocabulary words with
            prefix applied.

    This function takes a `vocab_words` list and returns a string
    with the prefix and the words with prefix applied, separated
     by ' :: '.

    For example: list('en', 'close', 'joy', 'lighten'),
    produces the following string: 'en :: enclose :: enjoy :: enlighten'.
    """
    # Replace the prefix with the empty string, so we can treat
    # all words in the list the same.
    prefix = vocab_words[0]
    vocab_words[0] = ''

    return ' :: '.join(map(
        lambda s: prefix + s,
        vocab_words
    ))


def remove_suffix_ness(word: str) -> str:
    """Remove the suffix from the word while keeping spelling in mind.

    :param word: str - of word to remove suffix from.
    :return: str - of word with suffix removed & spelling adjusted.

    For example: "heaviness" becomes "heavy", but "sadness" becomes "sad".
    """
    postfix = 'ness'

    if not word.endswith(postfix):
        return word

    word = word[:-len(postfix)]  # strip the postfix
    if word[-1] == 'i':
        word = word[:-1] + 'y'
    return word


def adjective_to_verb(sentence: str, index: int) -> str:
    """Change the adjective within the sentence to a verb.

    :param sentence: str - that uses the word in sentence.
    :param index: int - index of the word to remove and transform.
    :return: str - word that changes the extracted adjective to a verb.

    For example, ("It got dark as the sun set.", 2) becomes "darken".
    """
    pattern = re.compile(r'\w+')
    words = pattern.findall(sentence)
    try:
        return words[index] + 'en'
    except IndexError as exc:
        raise ValueError(
            f'Index {index} is too high! There are {len(words)} words.'
        ) from exc
