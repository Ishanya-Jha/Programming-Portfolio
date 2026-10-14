class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int],
                         k1: int, k2: int) -> int:
        differences = [
            abs(a - b) for a, b in zip(nums1, nums2)
        ]

        operations = k1 + k2

        if sum(differences) <= operations:
            return 0

        left = 0
        right = max(differences)

        # Find the smallest maximum difference we can reach
        while left < right:
            mid = (left + right) // 2
            needed = sum(max(0, diff - mid) for diff in differences)

            if needed <= operations:
                right = mid
            else:
                left = mid + 1

        limit = left

        # Reduce every difference to the limit
        remaining = operations
        for i in range(len(differences)):
            reduction = max(0, differences[i] - limit)
            differences[i] -= reduction
            remaining -= reduction

        # Use leftover operations to reduce the remaining largest differences
        differences.sort(reverse=True)

        for i in range(len(differences)):
            if remaining == 0:
                break
            if differences[i] == limit:
                differences[i] -= 1
                remaining -= 1

        return sum(diff * diff for diff in differences)
