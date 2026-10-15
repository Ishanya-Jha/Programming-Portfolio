class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        answer = 0

        for i in range(len(nums)):
            seen = set()

            for j in range(i, len(nums)):
                seen.add(nums[j])
                answer += len(seen) * len(seen)

        return answer
