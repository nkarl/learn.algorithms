w1 = [0, 1]
w2 = [0, 1, 4]
w3 = [0, 1, 4, 5]
w4 = [0, 1, 4, 5, 4]

def mwis(weights, n):
    if n == 0:
        return 0 # no weight
    if n == 1:
        return weights[1]
    s1 = mwis(weights, n-1)
    s2 = mwis(weights, n-2) + weights[n]
    return max(s1, s2)


print(w1, ": ", mwis(w1, len(w1)-1))
print(w2, ": ", mwis(w2, len(w2)-1))
print(w3, ": ", mwis(w3, len(w3)-1))
print(w4, ": ", mwis(w4, len(w4)-1))
