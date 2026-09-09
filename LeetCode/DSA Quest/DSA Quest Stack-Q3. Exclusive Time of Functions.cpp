class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {

        vector<int> ans(n, 0);

        stack<int> st;

        int previousTime = 0;

        for (int i = 0; i < logs.size(); i++) {

            // Split the log
            int firstColon = logs[i].find(':');
            int secondColon = logs[i].find(':', firstColon + 1);

            int id = stoi(logs[i].substr(0, firstColon));

            string type = logs[i].substr(
                firstColon + 1,
                secondColon - firstColon - 1
            );

            int time = stoi(logs[i].substr(secondColon + 1));


            if (type == "start") {

                // Previous function was running till now
                if (!st.empty()) {
                    ans[st.top()] += time - previousTime;
                }

                // New function starts
                st.push(id);

                previousTime = time;
            }

            else {

                // Function runs till this time, so add 1
                ans[st.top()] += time - previousTime + 1;

                // Function finished
                st.pop();

                previousTime = time + 1;
            }
        }

        return ans;
    }
};
