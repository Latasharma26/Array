class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // Build adjacency list for the tree
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int result = 0;

        // Helper DFS function
        function<int(int, int)> dfs = [&](int node, int parent) {
            int subtreeSum = values[node] % k; // Start with the node's value mod k
            
            for (int neighbor : adj[node]) {
                if (neighbor == parent) continue; // Skip the parent node
                int childSum = dfs(neighbor, node); // Recursive DFS
                subtreeSum += childSum;
            }
            
            // Check if we can form a separate component
            if (subtreeSum % k == 0) {
                result++; // Form a new component
                return 0; // Reset the subtree sum as it's now independent
            }
            
            return subtreeSum % k; // Return the modulo for further calculations
        };

        dfs(0, -1); // Start DFS from node 0 with no parent
        return result;
    }
};
