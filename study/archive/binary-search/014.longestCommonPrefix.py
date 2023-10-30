strs = ["flower", "flow", "flight"]


def isLCP(strs, tail) -> bool:
    prefix = strs[0][:tail]
    for s in strs:
        if s.find(prefix) != 0:
            return False
    return True


def search(strs, lo, hi) -> str:
    if lo > hi:
        return strs[0][:hi]
    m = lo + (hi - lo) // 2
    print(lo, m, hi)
    if isLCP(strs, m):
        return search(strs, m + 1, hi)
    else:
        return search(strs, lo, m - 1)


def LCP(strs) -> str:
    if len(strs) == 0:
        return ""
    if len(strs) == 1:
        return strs[0]
    shortest = len(strs[0])
    for s in strs:
        shortest = min(strs, key=len)
    return search(strs, 0, len(shortest))
    return 0


LCP(strs)
