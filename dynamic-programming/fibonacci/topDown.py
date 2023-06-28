# def fib(n):
    # if n==0:
        # return 0
    # if n==1:
        # return 1
    # return fib(n-1) + fib(n-2)

def fibo(n, cache):
    if n == 0:
        return cache[0]
    if n == 1:
        return cache[1]
    cache[n-1] = fibo(n -1, cache)
    cache[n-2] = fibo(n -2, cache)
    cache[n] = cache[n-1] + cache[n-2]
    return cache[n]
    # if cache[n] > -1:
        # return cache[n]
    # else:
        # cache[n] = fibo(n-1, cache) + fibo(n-2, cache)
        # return cache[n]

def fib(n):
    cache = [-1] * (n +1)
    cache[0], cache[1] = 0, 1
    result = fibo(n, cache)
    print(cache)
    return result
    

aa = fib(3)
print(f"result: {aa}")
bb = fib(5)
print(f"result: {bb}")
cc = fib(9)
print(f"result: {cc}")

# 0 1 2 3 4 5 6  7  8  9 10
# 0 1 1 2 3 5 8 13 21 34 55

# added newline char here, this only to practice reviewing code.
