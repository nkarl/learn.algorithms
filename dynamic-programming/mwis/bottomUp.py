w1 = [0, 1]
w2 = [0, 1, 4]
w3 = [0, 1, 4, 5]
w4 = [0, 1, 4, 5, 4]

def mwis(ws, n):
    cache = [0] * (n+1)
    cache[0], cache[1] = 0, ws[1]
    for i in range(2, n+1):
        cache[i] = max(ws[i-1], ws[i-2] + ws[i])
    return cache[n]


print(w1, ": ", mwis(w1, len(w1)-1))
print(w2, ": ", mwis(w2, len(w2)-1))
print(w3, ": ", mwis(w3, len(w3)-1))
print(w4, ": ", mwis(w4, len(w4)-1))
