def fib(n):
    if n==0:
        return 0
    if n==1:
        return 1
    return fib(n-1) + fib(n-2)


aa = fib(3)
print(f"result: {aa}")
bb = fib(5)
print(f"result: {bb}")
cc = fib(9)
print(f"result: {cc}")

# 0 1 2 3 4 5 6  7  8  9 10
# 0 1 1 2 3 5 8 13 21 34 55

# added newline char here, this only to practice reviewing code.
