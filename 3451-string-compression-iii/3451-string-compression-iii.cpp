#include <string>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int i = 0;
        int n = word.size();
        
        while (i < n) {
            char current_char = word[i];
            int count = 0;
            
            // Count occurrences of the same character up to 9
            while (i < n && word[i] == current_char && count < 9) {
                count++;
                i++;
            }
            
            // Append the count and the character to the result
            comp += to_string(count) + current_char;
        }
        
        return comp;
    }
};
