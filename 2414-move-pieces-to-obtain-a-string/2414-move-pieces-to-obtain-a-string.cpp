class Solution {
public:
    bool canChange(string start, string target) {
        // Filter out '_' and compare the order of 'L' and 'R'
        string filteredStart, filteredTarget;
        for (char c : start) if (c != '_') filteredStart += c;
        for (char c : target) if (c != '_') filteredTarget += c;
        
        if (filteredStart != filteredTarget) return false;

        int n = start.size();
        int i = 0, j = 0;

        while (i < n && j < n) {
            // Skip blanks in both strings
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;

            // If either index exceeds bounds, break
            if (i == n || j == n) break;

            // Check conditions for L and R
            if (start[i] != target[j]) return false;

            if (start[i] == 'L' && i < j) return false; // 'L' cannot move right
            if (start[i] == 'R' && i > j) return false; // 'R' cannot move left

            i++;
            j++;
        }

        return true;
    }
};
