class Solution {
public:

    int value(char c) {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        if (c == 'M') return 1000;

        return 0;
    }

    int romanToInt(string s) {

        int total = 0;

        for (int i = 0; i < s.size(); i++) {

            int current = value(s[i]);

            if (i + 1 < s.size() && current < value(s[i + 1])) {
                total -= current;
            }
            else {
                total += current;
            }
        }

        return total;
    }
};
