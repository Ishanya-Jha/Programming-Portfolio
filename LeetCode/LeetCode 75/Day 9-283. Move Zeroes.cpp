class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int index = 0;

        // Put all non-zero numbers in front
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != 0) {

                nums[index] = nums[i];
                index++;
            }
        }

        // Put zeroes in the remaining positions
        while (index < nums.size()) {

            nums[index] = 0;
            index++;
        }
    }
};
