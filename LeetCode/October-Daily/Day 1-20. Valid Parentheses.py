class Solution:
    def isValid(self, s: str) -> bool:

        stack = []

        for char in s:

            # Opening bracket
            if char == '(' or char == '[' or char == '{':
                stack.append(char)

            else:

                # Nothing to match
                if not stack:
                    return False

                top = stack.pop()

                # Check if brackets match
                if char == ')' and top != '(':
                    return False

                if char == ']' and top != '[':
                    return False

                if char == '}' and top != '{':
                    return False

        # Stack should be empty
        return len(stack) == 0
