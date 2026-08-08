class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int range = nums.size();

        int actualsum = (range * (range + 1)) / 2;

        int currsum = 0;

        for (int i = 0; i < nums.size(); i++) {
            currsum = currsum + nums[i];
        }

        int ans = actualsum - currsum;

        return ans;
    }
};
