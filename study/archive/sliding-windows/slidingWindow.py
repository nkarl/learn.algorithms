
# find the maximal sum with a window of size k from an array.
# s = [3, 5, 2, 1, 7]
# k = 2
# max_sum_window = [3, 5], [1, 7]
def getMaxSum(arr, k):
    max_sum = 0
    window_sum = 0
    p = 0

    for i in range(len(arr)):
        window_sum += arr[i]

        # sliding window; starting at i==k
        if (i + 1 - p) == k:
            max_sum = max(max_sum, window_sum)
            window_sum -= arr[p]
            p += 1

    return max_sum


# result = getMaxSum(s, k)
# print(result)

s = "123456789123456789"
k = 10


def slidingWindow(s, k):
    # subs = []
    # for i in range(len(s) - k + 1):
    #   subs += [s[i:i+k]]
    subs = [s[i:i+k] for i in range(len(s) - k + 1)]
    return "\n".join(subs)


result = slidingWindow(s, k)
print(result)
