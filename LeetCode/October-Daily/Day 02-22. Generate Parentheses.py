class Solution:
    def generateParenthesis(self, n: int) -> list[str]:

        ans = []

        def backtrack(s, open, close):

            # We have used all brackets
            if len(s) == 2 * n:
                ans.append(s)
                return

            # Add (
            if open < n:
                backtrack(s + "(", open + 1, close)

            # Add )
            if close < open:
                backtrack(s + ")", open, close + 1)

        backtrack("", 0, 0)

        return ans
