"""
     Calls merge recursively on an array.
"""
def merge_sort(nums):
    # bottom cases: empty or list of a single element.
    if len(nums) <= 1:
        return nums

    m = int(len(nums) / 2)
    left = merge_sort(nums[0:m])
    right = merge_sort(nums[m:])
    return merge(left, right)


"""
    Recursive method to sort and merge subproblems.
"""
def merge(left, right):
    l = r = 0; ret = []

    while l < len(left) and r < len(right):
        if left[l] < right[r]:
            ret.append(left[l]);  l += 1
        else:
            ret.append(right[r]); r += 1

    # append what is remained in either of the lists
    ret.extend(left[l:])
    ret.extend(right[r:])

    return ret
