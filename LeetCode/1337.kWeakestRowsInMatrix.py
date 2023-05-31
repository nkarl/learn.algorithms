import math

mat = [
    [1, 1, 0, 0, 0],
    [1, 1, 1, 1, 0],
    [1, 0, 0, 0, 0],
    [1, 1, 0, 0, 0],
    [1, 1, 1, 1, 1],
]


def binListToDecimal(l: list[int]) -> int:
    bin_str = "".join(map(str, l))
    res = int(bin_str, 2)
    return res


def kWeakestRows(mat: list[list[int]]):
    M = len(mat)
    N = len(mat[0])
    res = []

    maxV = 2**N
    for i in range(M):
        k = i
        print(mat[i])
        tmp = binListToDecimal(mat[i]) 
        v = N - int(math.log2(maxV - tmp))
        print(k, tmp, v)
        res += [[v, k]]
    return [x[1] for x in sorted(res)]
