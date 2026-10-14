class Solution:
    def checkValidString(self, s: str) -> bool:
        low = 0
        high = 0

        for char in s:

            if char == '(':
                low += 1
                high += 1

            elif char == ')':
                low -= 1
                high -= 1

            else:  # '*'
                low -= 1
                high += 1

            # Minimum cannot go below 0
            low = max(0, low)

            # Too many closing brackets
            if high < 0:
                return False

        return low == 0
