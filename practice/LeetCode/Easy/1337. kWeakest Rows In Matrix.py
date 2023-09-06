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


def sortByTrue(mat: list[list[int]]):
    M = len(mat)
    N = len(mat[0])
    res = []

    maxDec = 2**N
    for i in range(M):
        dec = binListToDecimal(mat[i])
        k = N - int(math.log2(maxDec - dec))
        res += [[k, i]]
    return sorted(res)


def kWeakestRows(mat: list[list[int]], k: int) -> list[int]:
    res = [x[1] for x in sortByTrue(mat)]
    return res[:k]


mat2 = [[1, 0], [1, 0], [1, 0], [1, 1]]

print(kWeakestRows(mat, len(mat)))
print(kWeakestRows(mat2, len(mat2)))
