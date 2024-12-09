class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> special(n - 1, 0);

        // Precompute the "specialness" of adjacent elements
        for (int i = 0; i < n - 1; ++i) {
            special[i] = (nums[i] % 2) != (nums[i + 1] % 2); // Different parity
        }

        // Build a prefix sum array for the "special" array
        vector<int> prefixSum(n, 0);
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + special[i - 1];
        }

        vector<bool> result;

        // Process each query
        for (const auto& query : queries) {
            int from = query[0];
            int to = query[1];

            // Check if all pairs in the range are "special"
            int specialCount = prefixSum[to] - prefixSum[from];
            result.push_back(specialCount == (to - from));
        }

        return result;
    }
};
