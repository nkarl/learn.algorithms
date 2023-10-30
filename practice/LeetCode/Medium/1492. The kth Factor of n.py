
n = 12
k = 3


def generateFactorList(n: int) -> [int]:
    factors = []
    for i in range(n):
        if n % (i + 1) == 0:
            factors += [i + 1]
    return factors


def kthFactor(n: int, k: int) -> int:
    factors = generateFactorList(n)
    if k > len(factors):
        return -1
    return factors[k-1]


def kthFactorLinear(n: int, k: int) -> int:
    for i in range(1, n + 1):
        if n % i == 0:
            k -= 1
            if k == 0:
                return i
    return -1


# kthFactor(12, 3)
kthFactorLinear(12, 3)
