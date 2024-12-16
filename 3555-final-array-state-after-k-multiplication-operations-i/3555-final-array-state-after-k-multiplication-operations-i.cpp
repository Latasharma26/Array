class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // Perform k operations
        while (k--) {
            // Find the minimum value and its index
            int minIndex = 0;
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] < nums[minIndex]) {
                    minIndex = i;
                }
            }
            // Multiply the minimum value by the multiplier
            nums[minIndex] *= multiplier;
        }
        return nums;
    }
};
