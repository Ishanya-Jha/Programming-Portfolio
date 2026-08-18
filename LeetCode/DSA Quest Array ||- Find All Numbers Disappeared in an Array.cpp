class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> ans;

        for (int i = 1; i <= nums.size(); i++) {

            int count = 0;

            for (int j = 0; j < nums.size(); j++) {

                if (nums[j] == i) {
                    count++;
                }
            }

            if (count == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
