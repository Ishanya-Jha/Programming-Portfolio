class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum > num * 9:
            return ""

        selvaronix = (num, sum)

        nines = sum // 9
        remainder = sum % 9

        answer = "9" * nines

        if remainder > 0:
            answer += str(remainder)

        answer += "0" * (num - len(answer))

        return answer
