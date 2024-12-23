#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

// No need to redefine TreeNode as it is already included in the LeetCode environment

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int totalSwaps = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;

            // Collect all values at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Calculate minimum swaps to sort the level
            totalSwaps += countMinSwaps(level);
        }

        return totalSwaps;
    }

private:
    int countMinSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> sortedNums;

        for (int i = 0; i < n; ++i) {
            sortedNums.push_back({nums[i], i});
        }

        sort(sortedNums.begin(), sortedNums.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || sortedNums[i].second == i) continue;

            int cycleSize = 0;
            int j = i;

            // Count the size of the cycle
            while (!visited[j]) {
                visited[j] = true;
                j = sortedNums[j].second;
                ++cycleSize;
            }

            // Add swaps for this cycle
            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }

        return swaps;
    }
};
