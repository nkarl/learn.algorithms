def canJumpFrom(position: int, nums: list[int]) -> bool:
    if position == len(nums) -1:
        return True
    farthest = min(position + nums[position],
                   len(nums) -1)
    for nextJump in range(position +1, farthest +1):
        if canJumpFrom(nextJump, nums):
            return True
    return False


def canJump(nums: list[int]):
    return canJumpFrom(0, nums)


nums = [2, 3, 1, 1, 4]
