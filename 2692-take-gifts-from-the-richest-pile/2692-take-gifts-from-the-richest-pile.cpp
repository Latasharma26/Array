class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        std::priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        
        // Perform k operations
        while (k--) {
            // Get the largest pile
            int maxGift = maxHeap.top();
            maxHeap.pop();
            
            // Calculate the remaining gifts
            int remainingGifts = std::floor(std::sqrt(maxGift));
            
            // Push the remaining gifts back into the heap
            maxHeap.push(remainingGifts);
        }
        
        // Calculate the total gifts remaining
        long long totalGifts = 0;
        while (!maxHeap.empty()) {
            totalGifts += maxHeap.top();
            maxHeap.pop();
        }
        
        return totalGifts;
    }
};