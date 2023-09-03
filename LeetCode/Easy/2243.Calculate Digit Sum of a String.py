s = "11111222223"
k = 3

output = 135


def reduce(s: str, k: int):
    if len(s) <= k:
        return s
    chunks = [sum(map(int, s[i:i+k])) for i in range(0, len(s), k)]
    s = "".join(map(str, chunks))
    return reduce(s, k)


result = reduce(s, k)
print(result)
