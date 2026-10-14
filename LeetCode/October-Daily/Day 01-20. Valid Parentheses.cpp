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


        //Approach-2 (Tricky)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char ch:s) {
            if (ch == '(')
			    st.push(')');
		    else if (ch == '{')
			    st.push('}');
            else if (ch == '[')
                st.push(']');
            else if (st.empty() || st.top() != ch)
                return false;
            else {
                st.pop();
            }
        }
        
        return st.empty();
    }
};

        // Everything should be closed
        return st.empty();
    }
};
