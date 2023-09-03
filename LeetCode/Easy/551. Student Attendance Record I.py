s = "PPALLL"
output = True


def reduce(s: str):
    return s.count('A') <= 1 and s.count('LLL') == 0


result = reduce(s)
print(result)
