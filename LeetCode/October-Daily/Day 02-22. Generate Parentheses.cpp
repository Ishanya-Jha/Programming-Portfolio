class Solution {
public:

    vector<string> ans;

    void backtrack(string s, int open, int close, int n) {

        // We have used all brackets
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // We can add '('
        if (open < n) {
            backtrack(s + "(", open + 1, close, n);
        }

        // We can add ')' only if there is an '(' to close
        if (close < open) {
            backtrack(s + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {

        backtrack("", 0, 0, n);

        return ans;
    }
};
