class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
         multiset<int> window; // To track the elements in the current window
    int left = 0;
    long long count = 0;

    for (int right = 0; right < nums.size(); ++right) {
        // Add the current element to the window
        window.insert(nums[right]);
        
        // Shrink the window until the condition is satisfied
        while (*window.rbegin() - *window.begin() > 2) {
            window.erase(window.find(nums[left]));
            ++left;
        }
        
        // Add the count of valid subarrays ending at `right`
        count += (right - left + 1);
    }
    
    return count;
    }
};