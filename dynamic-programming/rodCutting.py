"""
from CLRS 4th ed. Shit doesn't even work. Disappointing for such a highly praised book.

"""

#    0  1  2  3  4   5   6   7   8   9  10
p = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30]

"""
n == 0:
    ret q == 0
n == 1:
    q := p[n]==1
    for i in range(1, 1 + 1):
        q := max(q,
                 p[i==1]==1 + 0)
    ret q == 5
n == 2:
    q := p[n]==5
    for i in range(1, 2 + 1):
        q := max(q,
                 p[i==1]==1 +
                 p[i==1]==1 + 0)
n == 3:
    q := p[n]==8
    for i in range(1, 3 + 1):
        q := max(q,
                 p[i==1]==1 +
                 p[i==2]==5 +
                 p[i==1]==1 + 0)
"""

def cut(p, n):
    if n == 0:
        return 0
    q = -1
    for i in range(1, len(p)):
        q = max(q,
                p[i] + cut(p, n - 1))
    return q

# def mem_cut(p, n):
    # r = [0] * n + 1
    # for i in range(n):
        # r[i] = -1000
    # return mem_cut_aux(p, n, r)


# def mem_cut_aux(p, n, r):
    # if r[n] >= 0:
        # print(n)
        # return r[n]
    # if n == 0:
        # q = 0
    # else:
        # q = -1000
    # for i in range(1, n):
        # q = max(q, p[i] + mem_cut_aux(p, n - i, r))
    # r[n] = q
    # return q
