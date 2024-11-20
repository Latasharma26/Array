class Solution {
public:
    int takeCharacters(string s, int k) {
        // Count the total occurrences of 'a', 'b', and 'c'
        vector<int> total(3, 0);
        for (char c : s) {
            total[c - 'a']++;
        }
        
        // If any character appears less than k times, it's not possible
        if (total[0] < k || total[1] < k || total[2] < k) {
            return -1;
        }

        // Sliding window approach to find the largest valid middle window
        int n = s.size();
        int maxWindow = 0;
        vector<int> count(3, 0);  // count of 'a', 'b', 'c' in the current window
        int left = 0;

        for (int right = 0; right < n; ++right) {
            count[s[right] - 'a']++;

            // Shrink the window if it exceeds the allowable characters outside the window
            while (total[0] - count[0] < k || total[1] - count[1] < k || total[2] - count[2] < k) {
                count[s[left] - 'a']--;
                left++;
            }

            // Update the maximum window size
            maxWindow = max(maxWindow, right - left + 1);
        }

        // The result is the total length minus the largest valid middle window
        return n - maxWindow;
    }
};
