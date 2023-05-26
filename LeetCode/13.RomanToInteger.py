lookup = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}


def RomanToIntBasic(s: str) -> int:
    result = 0
    i = len(s) - 1
    while i >= 0:
        if lookup[s[i - 1]] < lookup[s[i]] and lookup[s[i - 1]] % lookup[s[i]] == 1:
            result += lookup[s[i]]
            result -= lookup[s[i - 1]]
            i -= 2
        else:
            result += lookup[s[i]]
            i -= 1
    return result


def romanToInt(s: str) -> int:
    result = 0
    stack = list(s)
    print(s, end="\t")
    while len(stack) > 0:
        if (
            len(stack) > 1
            and lookup[stack[-2]] % lookup[stack[-1]] == lookup[stack[-2]]
        ):
            result += lookup[stack[-1]]
            result -= lookup[stack[-2]]
            stack.pop()
        else:
            result += lookup[stack[-1]]
        stack.pop()
    return result


def test():
    tests = ["III", "VII", "IV", "IX", "XIII", "XL"]

    for s in tests:
        print(romanToInt(s))


test()
