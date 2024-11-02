#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Handle cases where k >= n
        
        // Step 1: Copy the last k elements
        vector<int> temp(nums.end() - k, nums.end());
        
        // Step 2: Shift the first n - k elements to the right
        for (int i = n - 1; i >= k; --i) {
            nums[i] = nums[i - k];
        }
        
        // Step 3: Place the last k elements at the beginning
        for (int i = 0; i < k; ++i) {
            nums[i] = temp[i];
        }
    }
};
