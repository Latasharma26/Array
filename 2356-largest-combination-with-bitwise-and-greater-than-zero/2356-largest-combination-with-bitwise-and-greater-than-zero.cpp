
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

    static const int BITS_IN_INT32 = 32;

public:
    int largestCombination(const vector<int>& candidates) const {
        int largestCombination = 0;

        for (int shifts = 0; shifts < BITS_IN_INT32; ++shifts) {
            int frequencyCurrentBit = 0;
            for (int value : candidates) {
                frequencyCurrentBit += (value >> shifts) & 1;
            }
            largestCombination = max(largestCombination, frequencyCurrentBit);
        }
        return largestCombination;
    }
};