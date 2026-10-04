class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;

        // Starting point
        st.push(-1);

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {

                // Store index of '('
                st.push(i);
            }

            else {

                // Remove the matching '('
                st.pop();

                // No opening bracket to match
                if (st.empty()) {
                    st.push(i);
                }

                else {

                    // Calculate valid length
                    int length = i - st.top();

                    ans = max(ans, length);
                }
            }
        }

        return ans;
    }
};
