class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordIndex = 1; // 1-based index
        size_t pos = 0;    // Position in the sentence
        
        while (pos < sentence.length()) {
            // Find the end of the current word
            size_t endPos = sentence.find(' ', pos);
            if (endPos == string::npos) {
                endPos = sentence.length(); // Last word
            }
            
            // Extract the current word
            string currentWord = sentence.substr(pos, endPos - pos);
            
            // Check if searchWord is a prefix of currentWord
            if (currentWord.find(searchWord) == 0) {
                return wordIndex;
            }
            
            // Move to the next word
            pos = endPos + 1;
            wordIndex++;
        }
        
        return -1; // No match found
    }
};
