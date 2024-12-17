#include <queue>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // Step 1: Count the frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Step 2: Use a max-heap to store characters by lexicographical order
        priority_queue<pair<char, int>> maxHeap;
        for (auto& entry : freq) {
            maxHeap.push({entry.first, entry.second});
        }
        
        string result = "";
        while (!maxHeap.empty()) {
            auto [ch, count] = maxHeap.top();
            maxHeap.pop();
            
            // Determine how many times we can append the current character
            int useCount = min(repeatLimit, count);
            
            // Append the character 'useCount' times to the result
            result.append(useCount, ch);
            count -= useCount;
            
            // If more of the current character is left, we need to break the sequence
            if (count > 0) {
                if (maxHeap.empty()) break;  // No other characters left to break the sequence
                
                // Get the next lexicographically largest character
                auto [nextCh, nextCount] = maxHeap.top();
                maxHeap.pop();
                
                // Append the next character once to break the sequence
                result.push_back(nextCh);
                nextCount--;
                
                // Put back the remaining counts of both characters into the heap
                if (nextCount > 0) {
                    maxHeap.push({nextCh, nextCount});
                }
                maxHeap.push({ch, count});
            }
        }
        
        return result;
    }
};
