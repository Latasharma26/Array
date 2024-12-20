#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        bool isOddLevel = false;

        // BFS to traverse the tree level by level
        while (!q.empty()) {
            int levelSize = q.size();
            vector<TreeNode*> currentLevelNodes;
            vector<int> currentLevelValues;

            // Collect nodes and values at the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentLevelNodes.push_back(node);
                currentLevelValues.push_back(node->val);

                // Enqueue children for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Reverse the node values at odd levels
            if (isOddLevel) {
                int idx = 0;
                for (int i = currentLevelValues.size() - 1; i >= 0; i--) {
                    currentLevelNodes[idx]->val = currentLevelValues[i];
                    idx++;
                }
            }

            isOddLevel = !isOddLevel;  // Flip the flag for next level
        }

        return root;
    }
};
