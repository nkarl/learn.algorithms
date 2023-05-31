accounts = [
    [1, 2, 3],
    [3, 2, 1],
]

def richestCat(mat: list[list]):
    m = -1
    for i in range(len(mat)):
        m = max(m, sum(mat[i]))
    return m
