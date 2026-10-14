class Solution:
    def minInsertions(self, s: str) -> int:
        open_count = 0
        insertions = 0
        i = 0

        while i < len(s):

            if s[i] == '(':
                open_count += 1

            else:
                # Check if the next character is also ')'
                if i + 1 < len(s) and s[i + 1] == ')':
                    i += 1
                else:
                    # We need one more ')' to make a pair
                    insertions += 1

                if open_count > 0:
                    # Match this pair with an opening bracket
                    open_count -= 1
                else:
                    # No '(' to match, so add one
                    insertions += 1

            i += 1

        # Every unmatched '(' needs two closing brackets
        insertions += open_count * 2

        return insertions
        
