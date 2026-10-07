class Solution {
public:
    set<string> ans;

    void solve(string& s, int i, int leftRemove, int rightRemove,
               int balance, string curr) {

        if (balance < 0) return;

        if (i == s.size()) {
            if (leftRemove == 0 && rightRemove == 0 && balance == 0) {
                ans.insert(curr);
            }
            return;
        }

        char c = s[i];

        // Remove '('
        if (c == '(' && leftRemove > 0) {
            solve(s, i + 1, leftRemove - 1, rightRemove,
                  balance, curr);
        }

        // Remove ')'
        if (c == ')' && rightRemove > 0) {
            solve(s, i + 1, leftRemove, rightRemove - 1,
                  balance, curr);
        }

        // Keep character
        curr += c;

        if (c == '(') {
            solve(s, i + 1, leftRemove, rightRemove,
                  balance + 1, curr);
        }
        else if (c == ')') {
            solve(s, i + 1, leftRemove, rightRemove,
                  balance - 1, curr);
        }
        else {
            solve(s, i + 1, leftRemove, rightRemove,
                  balance, curr);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0;
        int rightRemove = 0;

        // Find required removals
        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {
                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//alternate 
      class Solution {
private:
    unordered_set<string> st;
    int n;

    void solve(const string& s, int i, string& curr, int count, int& maxLen) {
        if (count < 0)  //invalid
            return;

        if (i == n) {
            if (count == 0) {
                if (curr.length() > maxLen) {        // found a longer valid string
                    maxLen = curr.length();
                    st.clear();
                }
                
                if(curr.length() == maxLen) {
                    st.insert(curr);
                }
                
            }
            return;
        }

        if (s[i] != '(' && s[i] != ')') {                     // letter: always keep
            curr.push_back(s[i]);
            solve(s, i + 1, curr, count, maxLen);
            curr.pop_back();
            return;
        }

        //Do
        curr.push_back(s[i]);

        //Explore
        solve(s, i + 1, curr, count + (s[i] == '(' ? 1 : -1), maxLen);

        //Undo and explore
        curr.pop_back();
        solve(s, i + 1, curr, count, maxLen);
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        int maxLen = 0;
        st.clear();

        string curr = "";
        solve(s, 0, curr, 0, maxLen);

        return vector<string>(begin(st), end(st));
    }
};

        solve(s, 0, leftRemove, rightRemove, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};
