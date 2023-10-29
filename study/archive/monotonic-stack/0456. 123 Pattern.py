"""
    NOTE:
    It is very easy to make the mistake of applying Sliding Window for this
    problem. This is because the elements need not to be consecutive.

    For example, my first naive solution, using Sliding Window, passes three
    examples:
        ex1 = [1,2,3,4]
        ex2 = [3,1,4,2]
        ex3 = [-1,3,2,0]

    It fails on the fourth example, where the last index k is located towards the
    end of the array.
        ex4 = [3,5,0,3,4]
"""


def naiveSolution(nums: [int]) -> bool:
    """
        This is incorrect solution.
    """
    for i in range(len(nums) - 2):
        j = i + 1
        k = i + 2
        if nums[i] < nums[k] and nums[k] < nums[j]:
            return True
    return False


def solution(nums: [int]) -> bool:
    """
        Requirement:
        - i < j < k, and
        - si < sk < sj where
            si := nums[i] and
            sj := nums[j] and
            sk := nums[k]

        We use the monotonic stack to solve the problem.
        A number becomes candidate for sk when there is a number on the
        left that is larger than it. This number is sj.
    """
    print(nums)
    import sys
    stack = []
    si = 0
    sj = 0
    sk = -sys.maxsize
    for n in nums[::-1]:
        si = n
        print(f"n={n}, sk={sk}, stack={stack}", end=' ')
        if n < sk:
            print()
            return True
        while stack and stack[-1] < n:
            sk = stack.pop()
            print(f"| sk={sk} stack={stack}", end=' ')
        print()
        stack.append(n)
    print("i < j < k")
    print("si < sk < sj")
    print(si, sk, sj)
    return False


ex4 = [3, 5, 0, 3, 4]
ex5 = [3, 4, 3, 4]
# solution(ex4)
solution(ex5)
