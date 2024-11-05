class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        
        // Traverse the string in steps of 2 (pair by pair)
        for (int i = 0; i < s.size(); i += 2) {
            // If the two characters in the pair are different, we need to change one of them
            if (s[i] != s[i + 1]) {
                changes++;
            }
        }
        
        return changes;
    }
};
