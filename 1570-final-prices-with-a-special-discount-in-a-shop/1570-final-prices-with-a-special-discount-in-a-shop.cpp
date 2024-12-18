class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(n);
        
        for (int i = 0; i < n; ++i) {
            result[i] = prices[i]; // Default price if no discount is found
            for (int j = i + 1; j < n; ++j) {
                if (prices[j] <= prices[i]) {
                    result[i] -= prices[j];
                    break;
                }
            }
        }
        
        return result;
    }
};
