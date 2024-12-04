class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        // If str2 is longer than str1, it's impossible to form str2 as a subsequence
        if (m > n) {
            return false;
        }
        
        int j = 0; // Pointer for str2
        
        for (int i = 0; i < n && j < m; ++i) {
            // Direct match
            if (str1[i] == str2[j]) {
                ++j;
            } 
            // Cyclic increment match
            else if ((str1[i] - 'a' + 1) % 26 == (str2[j] - 'a')) {
                ++j;
            }
        }
        
        // If we have matched all of str2, return true
        return j == m;
    }
};

