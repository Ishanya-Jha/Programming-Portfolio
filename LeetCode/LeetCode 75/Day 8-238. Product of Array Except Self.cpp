class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, 1);

        // Product of everything on the left
        int left = 1;

        for (int i = 0; i < n; i++) {

            ans[i] = left * ans[i];

            left = left * nums[i];
        }

        // Product of everything on the right
        int right = 1;

        for (int i = n - 1; i >= 0; i--) {

            ans[i] = ans[i] * right;

            right = right * nums[i];
        }

        return ans;
    }
};
