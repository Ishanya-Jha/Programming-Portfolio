class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0)
            return false;

        int n = x;
        long long temp = 0;

        while (n > 0) {
            int d = n % 10;
            temp = temp * 10 + d;
            n /= 10;
        }

        return temp == x;
    }
};
