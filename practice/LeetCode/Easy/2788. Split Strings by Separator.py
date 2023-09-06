words = ["one.two.three", "four.five", "six"]
separator = "."
ouput = ["one", "two", "three", "four", "five", "six"]


def splitWord(word, sep):
    group, chunk = [], []
    for i in range(len(word)):
        c = word[i]
        if c == sep:
            if len(chunk) > 0:
                group += ["".join(chunk)]
            chunk = []
        else:
            chunk += c
            if i == len(word) - 1:
                group += ["".join(chunk)]
    return group


def reduce(words, sep):
    sentence = []
    for word in words:
        sentence += splitWord(word, sep)
    return sentence


result = reduce(words, separator)
print(result)
