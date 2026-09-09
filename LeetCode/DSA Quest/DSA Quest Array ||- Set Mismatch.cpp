class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        vector<int> count(nums.size() + 1, 0);

        int duplicate = 0;
        int missing = 0;

        // Count how many times each number appears
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }

        // Find duplicate and missing
        for (int i = 1; i <= nums.size(); i++) {

            if (count[i] == 2) {
                duplicate = i;
            }

            if (count[i] == 0) {
                missing = i;
            }
        }

        return {duplicate, missing};
    }
};
