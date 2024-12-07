class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // Helper function to determine if a penalty is achievable
        auto canAchieve = [&](int penalty) {
            int operations = 0;
            for (int balls : nums) {
                if (balls > penalty) {
                    // Calculate the operations required to reduce balls <= penalty
                    operations += (balls - 1) / penalty;
                }
            }
            return operations <= maxOperations;
        };
        
        // Binary search for the minimum penalty
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int result = high; // Initialize result to the maximum possible penalty
        
        while (low <= high) {
            int mid = low + (high - low) / 2; // Midpoint of current range
            if (canAchieve(mid)) {
                result = mid; // Update result with a smaller possible penalty
                high = mid - 1; // Try smaller penalties
            } else {
                low = mid + 1; // Try larger penalties
            }
        }
        
        return result;
    }
};
