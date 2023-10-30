
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
    print(factors)
    if k > len(factors):
        return -1
    return factors[k-1]


kthFactor(12, 3)
