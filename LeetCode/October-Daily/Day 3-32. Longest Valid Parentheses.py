class Solution:
    def longestValidParentheses(self, s: str) -> int:

        stack = []

        # Starting point
        stack.append(-1)

        ans = 0

        for i in range(len(s)):

            if s[i] == '(':

                # Store index of '('
                stack.append(i)

            else:

                # Remove the matching '('
                stack.pop()

                # No '(' to match
                if not stack:
                    stack.append(i)

                else:

                    # Find length of valid part
                    length = i - stack[-1]

                    ans = max(ans, length)

        return ans
