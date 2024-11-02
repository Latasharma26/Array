class Solution {
public:
    bool isCircularSentence(string sentence) {
        // Split the sentence into words
        vector<string> words;
        stringstream ss(sentence);
        string word;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Check if each word's last character matches the next word's first character
        for (int i = 0; i < words.size() - 1; ++i) {
            if (words[i].back() != words[i + 1].front()) {
                return false;
            }
        }
        
        // Check if the last word's last character matches the first word's first character
        return words.back().back() == words.front().front();
    }
};
