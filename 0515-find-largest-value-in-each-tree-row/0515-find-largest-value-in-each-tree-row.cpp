#include <vector>
#include <queue>
#include <limits>
using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {}; // Return an empty vector if the tree is empty
        
        vector<int> result;
        queue<TreeNode*> q; // Queue for level-order traversal
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            int levelMax = numeric_limits<int>::min(); // Minimum value for this level
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Update the maximum value for this level
                levelMax = max(levelMax, node->val);
                
                // Add children to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Add the largest value of this level to the result
            result.push_back(levelMax);
        }
        
        return result;
    }
};

