class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)

        tree_sum = [0] * (4 * n)
        tree_square = [0] * (4 * n)
        lazy = [0] * (4 * n)

        def update(node, left, right, ql, qr):
            if ql <= left and right <= qr:
                length = right - left + 1
                tree_square[node] += 2 * tree_sum[node] + length
                tree_sum[node] += length
                lazy[node] += 1
                return

            mid = (left + right) // 2
            push(node, left, right)

            if ql <= mid:
                update(node * 2, left, mid, ql, qr)
            if qr > mid:
                update(node * 2 + 1, mid + 1, right, ql, qr)

            tree_sum[node] = tree_sum[node * 2] + tree_sum[node * 2 + 1]
            tree_square[node] = (
                tree_square[node * 2] + tree_square[node * 2 + 1]
            )

        def push(node, left, right):
            if lazy[node] == 0 or left == right:
                return

            mid = (left + right) // 2
            for child, a, b in (
                (node * 2, left, mid),
                (node * 2 + 1, mid + 1, right),
            ):
                length = b - a + 1
                add = lazy[node]
                tree_square[child] += (
                    2 * add * tree_sum[child] + add * add * length
                )
                tree_sum[child] += add * length
                lazy[child] += add

            lazy[node] = 0

        last_seen = {}
        answer = 0
        current_sum = 0

        for right, num in enumerate(nums):
            previous = last_seen.get(num, -1)

            update(1, 0, n - 1, previous + 1, right)

            current_sum = tree_square[1] % MOD
            answer = (answer + current_sum) % MOD
            last_seen[num] = right

        return answer
