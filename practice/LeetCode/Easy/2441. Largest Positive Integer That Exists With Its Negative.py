
# nums = [-1,2,-3,3]
nums = [-1, 10, 6, 7, -7, 1]
output = 7


def func(nums):
    s = {}
    maxi = -1
    for n in nums:
        if -n in s:
            maxi = max(maxi, abs(n))
        else:
            s[n] = 0
    return -1 if maxi == -1 else maxi


print(func(nums) == output)
