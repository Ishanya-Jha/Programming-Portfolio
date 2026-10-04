class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            // Opening bracket
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }

            else {

                // Nothing to match
                if (st.empty()) {
                    return false;
                }

                char top = st.top();
                st.pop();

                // Check if brackets match
                if (s[i] == ')' && top != '(') {
                    return false;
                }

                if (s[i] == ']' && top != '[') {
                    return false;
                }

                if (s[i] == '}' && top != '{') {
                    return false;
                }
            }
        }

        // Everything should be closed
        return st.empty();
    }
};
