class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        nums.sort(key=lambda x: x * x)

        mid = len(nums) // 2

        bigger = sum(x * x for x in nums[mid:])
        smaller = sum(x * x for x in nums[:mid])

        return bigger - smaller
