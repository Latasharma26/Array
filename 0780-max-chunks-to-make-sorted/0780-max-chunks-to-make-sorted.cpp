#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0;
        int current_max = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            current_max = max(current_max, arr[i]);
            if (current_max == i) {
                chunks++;
            }
        }
        
        return chunks;
    }
};
