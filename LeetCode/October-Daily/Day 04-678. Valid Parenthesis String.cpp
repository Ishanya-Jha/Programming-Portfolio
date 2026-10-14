class Solution {
public:
    bool checkValidString(string s) {

        int low = 0;
        int high = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {

                low++;
                high++;
            }

            else if (s[i] == ')') {

                low--;
                high--;
            }

            else {  // '*'

                // '*' can act as ')'
                low--;

                // '*' can act as '('
                high++;
            }

            // We cannot have fewer than 0 open brackets
            low = max(0, low);

            // Too many ')' means impossible
            if (high < 0) {
                return false;
            }
        }

        // We should be able to have exactly 0 open brackets
        return low == 0;
    }
};
