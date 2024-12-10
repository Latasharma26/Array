class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int maxLength = -1;

        // Iterate over all possible substring lengths
        for (int len = 1; len <= n; ++len) {
            unordered_map<string, int> substringCount;

            // Check all substrings of length `len`
            for (int i = 0; i <= n - len; ++i) {
                string substring = s.substr(i, len);

                // Check if the substring is "special" (consists of only one character)
                char firstChar = substring[0];
                bool isSpecial = true;
                for (char c : substring) {
                    if (c != firstChar) {
                        isSpecial = false;
                        break;
                    }
                }

                // If special, count its occurrences
                if (isSpecial) {
                    substringCount[substring]++;
                    // Update maxLength if the substring occurs at least three times
                    if (substringCount[substring] >= 3) {
                        maxLength = max(maxLength, len);
                    }
                }
            }
        }

        return maxLength;
    }
};
