class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        
        // Step 1: Compute prefix sums
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        // Step 2: Prepare left and right arrays
        vector<int> left(n, 0), right(n, n - k);

        // Left array: Maximum sum subarray indices from the left
        int maxSumLeft = prefixSum[k] - prefixSum[0];
        for (int i = k; i < n; i++) {
            if (prefixSum[i + 1] - prefixSum[i + 1 - k] > maxSumLeft) {
                maxSumLeft = prefixSum[i + 1] - prefixSum[i + 1 - k];
                left[i] = i + 1 - k;
            } else {
                left[i] = left[i - 1];
            }
        }

        // Right array: Maximum sum subarray indices from the right
        int maxSumRight = prefixSum[n] - prefixSum[n - k];
        for (int i = n - k - 1; i >= 0; i--) {
            if (prefixSum[i + k] - prefixSum[i] >= maxSumRight) {
                maxSumRight = prefixSum[i + k] - prefixSum[i];
                right[i] = i;
            } else {
                right[i] = right[i + 1];
            }
        }

        // Step 3: Find the maximum sum of three subarrays
        vector<int> result(3, 0);
        int maxTotal = 0;
        for (int mid = k; mid <= n - 2 * k; mid++) {
            int l = left[mid - 1];  // Best subarray on the left
            int r = right[mid + k];  // Best subarray on the right
            int total = (prefixSum[l + k] - prefixSum[l]) +
                        (prefixSum[mid + k] - prefixSum[mid]) +
                        (prefixSum[r + k] - prefixSum[r]);
            if (total > maxTotal) {
                maxTotal = total;
                result = {l, mid, r};
            }
        }

        return result;
    }
};