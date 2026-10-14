class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        result = ""
        balance = 0

        for char in s:

            if char == '(':
                # Keep '(' only if it is not the outermost one
                if balance > 0:
                    result += char
                balance += 1

            else:
                balance -= 1

                # Keep ')' only if it is not the outermost one
                if balance > 0:
                    result += char

        return result
