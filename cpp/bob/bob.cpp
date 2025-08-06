#include "bob.h"
#include <algorithm>
#include <cctype>

namespace bob {

std::string_view hey(std::string_view text) {
    bool isEmpty = true;
    bool hasAlpha = false;
    bool hasLower = false;
    char lastNonSpace = '\0';

    for (char c : text) {
        if (std::isspace(static_cast<unsigned char>(c))) {
            continue;
        }

        isEmpty = false;
        lastNonSpace = c;

        if (!std::isalpha(static_cast<unsigned char>(c))) {
            continue;
        }

        hasAlpha = true;
        if (std::islower(static_cast<unsigned char>(c))) {
            hasLower = true;
        }
    }

    if (isEmpty) {
        return "Fine. Be that way!";
    }

    const bool isQuestion = (lastNonSpace == '?');
    const bool isYell = hasAlpha && !hasLower;

    if (isQuestion && isYell) {
        return "Calm down, I know what I'm doing!";
    }

    if (isQuestion) {
        return "Sure.";
    }

    if (isYell) {
        return "Whoa, chill out!";
    }

    return "Whatever.";
}

}  // namespace bob
