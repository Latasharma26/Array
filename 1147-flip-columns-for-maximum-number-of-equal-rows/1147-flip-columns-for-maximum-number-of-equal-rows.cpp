#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_map<string, int> patternCount;
        int maxRows = 0;

        for (int i = 0; i < m; ++i) {
            string pattern;
            int count = 1;

            for (int j = 1; j < n; ++j) {
                if (matrix[i][j - 1] == matrix[i][j]) {
                    ++count;
                } else {
                    pattern += to_string(count) + '*';
                    count = 1;
                }
            }

            // Append the final count
            pattern += to_string(count);

            // Update the pattern count
            ++patternCount[pattern];
            maxRows = max(maxRows, patternCount[pattern]);
        }

        return maxRows;
    }
};
