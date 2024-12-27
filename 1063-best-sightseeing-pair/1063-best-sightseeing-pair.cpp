class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int maxI = values[0]; // Initialize max(values[i] + i)

        for (int j = 1; j < values.size(); ++j) {
            // Calculate score for the pair (i, j)
            maxScore = max(maxScore, maxI + values[j] - j);
            // Update maxI for the next iteration
            maxI = max(maxI, values[j] + j);
        }

        return maxScore;
    }
};
