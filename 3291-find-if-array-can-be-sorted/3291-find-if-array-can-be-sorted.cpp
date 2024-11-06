#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    bool canSortArray(std::vector<int>& nums) {
        int pre_mx = INT_MIN;  // Equivalent to -inf in Python
        int i = 0;
        int n = nums.size();
        
        while (i < n) {
            int j = i + 1;
            int cnt = __builtin_popcount(nums[i]);  // Equivalent to nums[i].bit_count() in Python
            int mi = nums[i], mx = nums[i];
            
            while (j < n && __builtin_popcount(nums[j]) == cnt) {
                mi = std::min(mi, nums[j]);
                mx = std::max(mx, nums[j]);
                j++;
            }
            
            if (pre_mx > mi) {
                return false;
            }
            
            pre_mx = mx;
            i = j;
        }
        
        return true;
    }
};
