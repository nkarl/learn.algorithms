
def getMaxSum(arr, k):
    maxSum = 0
    windowSum = 0
    p = 0

    for i in range(len(arr)):
        windowSum += arr[i]

        if (i - p + 1) == k:
            maxSum = max(maxSum, windowSum)
            windowSum -= arr[p]
            p += 1

    return maxSum


