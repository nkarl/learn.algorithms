# tail recursion practice on the Fibonacci sequence

def fib(n):
    curr, next = 0, 1
    for i in range(2, n+1):
        curr, next = next, curr + next
    return next


def fibo(i, n, curr, next):
    if i == n:
        return curr
    return fibo(i+1, n, next, curr+next)


def fib2(n):
    return fibo(0, n, 0, 1)

# def fib(n):
    # if n==0:
        # return 0
    # if n==1:
        # return 1
    # return fib(n-1) + fib(n-2)


aa = fib(3)
print(f"result: {aa}")
bb = fib(5)
print(f"result: {bb}")
cc = fib(9)
print(f"result: {cc}")

# 0 1 2 3 4 5 6  7  8  9 10
# 0 1 1 2 3 5 8 13 21 34 55

# added newline char here, this only to practice reviewing code.
