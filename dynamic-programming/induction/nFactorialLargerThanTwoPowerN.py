# Statement: n! > 2^n, for all n >= 4
#
# n! = Product of all (n-i) for all i=0,1,2,...,n-1
#   3! = 3*2*1 = 6
#   4! = 24
# 2^n
#   2^3 = 8
#   2^4 = 16

def factorial(n):
    if n == 3:
        return 6
    return n * factorial(n-1)

def twoPowerN(n):
    if n == 3:
        return 8
    return 2 * twoPowerN(n-1)

def proof(n):
    return factorial(n) > twoPowerN(n)


print(factorial(4), twoPowerN(4), proof(4))
print(factorial(5), twoPowerN(5), proof(5))
print(factorial(6), twoPowerN(6), proof(6))
