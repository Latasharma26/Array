#include <vector>
#include <unordered_map>
#include <algorithm> // for std::max

class Solution {
public:
    long long maximumSubarraySum(std::vector<int>& nums, int k) {
        long long res = 0; // Stores the maximum sum
        std::unordered_map<int, int> freqMap; // Tracks frequencies of elements in the window
        long long curSum = 0; // Tracks the sum of the current window
        int uniqueCount = 0; // Tracks the number of unique elements in the window

        for (int i = 0; i < nums.size(); i++) {
            // Remove the element that's sliding out of the window
            if (i - k >= 0) {
                int removedElement = nums[i - k];
                freqMap[removedElement]--;
                if (freqMap[removedElement] == 0) {
                    freqMap.erase(removedElement);
                    uniqueCount--;
                }
                curSum -= removedElement;
            }

            // Add the current element to the window
            int currentElement = nums[i];
            if (freqMap.find(currentElement) == freqMap.end()) {
                uniqueCount++;
            }
            freqMap[currentElement]++;
            curSum += currentElement;

            // Update the maximum sum if the window contains exactly 'k' unique elements
            if (uniqueCount == k) {
                res = std::max(res, curSum);
            }
        }

        return res;
    }
};
