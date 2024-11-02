
class Solution {
public:
    bool check(vector<int>& nums) {
        int countBreaks = 0;
        int n = nums.size();
        
        // Count the number of "breaks" in the increasing order
        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[(i + 1) % n]) {
                countBreaks++;
            }
            // If there are more than one break, return false
            if (countBreaks > 1) {
                return false;
            }
        }
        
        return true;
    }
};