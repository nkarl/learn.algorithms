def recursive_multiply(x: str, y: str, n: int) -> int:
    if n == 1:
        return int(x) * int(y)
    s = n // 2
    a, b = x[:s], x[s:]
    c, d = y[:s], y[s:]
    ac = recursive_multiply(a, c, s)
    ad = recursive_multiply(a, d, s)
    bc = recursive_multiply(b, c, s)
    bd = recursive_multiply(b, d, s)

    return (10**n) * ac + (10 ** (n // 2)) * (ad + bc) + bd
    # return ((10 ** (n // 2)) * int(a) + int(b)) * ((10 ** (n // 2)) * int(c) + int(d))


def karatsuba(x: str, y: str, n: int) -> int:
    if n == 1:
        return int(x) * int(y)
    s = n // 2
    a, b = x[:s], x[s:]
    c, d = y[:s], y[s:]
    ac = recursive_multiply(a, c, s)
    bd = recursive_multiply(b, d, s)
    pq = recursive_multiply(a + b, c + d, s)
    adbc = pq - ac - bd

    return (10**n) * ac + (10 ** (n // 2)) * (adbc) + bd
