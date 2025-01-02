class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // Set of vowels for easy checking
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        // Step 1: Preprocess the words to mark if a word starts and ends with a vowel
        int n = words.size();
        vector<int> vowel_count(n, 0);
        
        // Mark words that start and end with a vowel
        for (int i = 0; i < n; ++i) {
            string word = words[i];
            if (vowels.count(word[0]) && vowels.count(word[word.size() - 1])) {
                vowel_count[i] = 1;
            }
        }
        
        // Step 2: Create a prefix sum array
        vector<int> prefix(n, 0);
        prefix[0] = vowel_count[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + vowel_count[i];
        }
        
        // Step 3: Process each query
        vector<int> result;
        for (auto& query : queries) {
            int li = query[0], ri = query[1];
            if (li == 0) {
                result.push_back(prefix[ri]);
            } else {
                result.push_back(prefix[ri] - prefix[li - 1]);
            }
        }
        
        return result;
    }
};
