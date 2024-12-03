class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int spaceIndex = 0; // Pointer for the spaces array
        int n = spaces.size();

        for (int i = 0; i < s.size(); ++i) {
            // If the current index matches a space index, add a space
            if (spaceIndex < n && i == spaces[spaceIndex]) {
                result += ' ';
                ++spaceIndex; // Move to the next space index
            }
            // Add the current character
            result += s[i];
        }
        return result;
    }
};
