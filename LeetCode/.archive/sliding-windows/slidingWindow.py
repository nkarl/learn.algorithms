
# s = [3, 5, 2, 1, 7]
# k = 2


# def getMaxSum(arr, k):
# maxSum = 0
# windowSum = 0
# p = 0

# for i in range(len(arr)):
# windowSum += arr[i]

# if (i - p + 1) == k:
# maxSum = max(maxSum, windowSum)
# windowSum -= arr[p]
# p += 1

# return maxSum


# result = getMaxSum(s, k)
# print(result)

s = "123456789123456789"

k = 10
li = [s[i:i+k] for i in range(len(s) - k + 1)]
print("\n".join(li))
