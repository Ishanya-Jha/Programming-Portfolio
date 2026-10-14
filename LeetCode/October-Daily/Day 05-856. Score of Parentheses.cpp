class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {

            if (c == '(') {
                st.push(0);
            } 
            else {
                int inside = st.top();
                st.pop();

                int score = 0;

                if (inside == 0) {
                    // "()" = 1
                    score = 1;
                } 
                else {
                    // "(A)" = 2 * A
                    score = 2 * inside;
                }

                st.top() += score;
            }
        }

        return st.top();
    }
};
