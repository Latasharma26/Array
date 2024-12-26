class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // Check if the problem is solvable
        if ((totalSum + target) % 2 != 0 || totalSum < abs(target)) {
            return 0;
        }
        
        int sum = (totalSum + target) / 2;
        
        // DP array to store the count of ways to achieve each sum
        vector<int> dp(sum + 1, 0);
        dp[0] = 1; // Base case: one way to achieve sum 0
        
        for (int num : nums) {
            for (int j = sum; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[sum];
    }
};
