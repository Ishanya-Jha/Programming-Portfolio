class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int answer = 0;

        for (char c : s) {

            if (c == '(') {
                open++;
            }
            else {
                if (open > 0) {
                    // Match with an opening bracket
                    open--;
                }
                else {
                    // Need to add '('
                    answer++;
                }
            }
        }

        // Add ')' for remaining '('
        answer += open;

        return answer;
    }
};
