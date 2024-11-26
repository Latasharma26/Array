class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // Step 1: Initialize in-degree array
        vector<int> in_degree(n, 0);
        
        // Step 2: Compute in-degree for each node
        for (const auto& edge : edges) {
            in_degree[edge[1]]++; // Increment in-degree for the target node
        }
        
        // Step 3: Find nodes with in-degree 0
        int champion = -1; // Initially, no champion is identified
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) {
                // If more than one node has in-degree 0, return -1
                if (champion != -1) return -1;
                champion = i; // Update champion
            }
        }
        
        // Step 4: Return the champion or -1 if no valid champion exists
        return champion;
    }
};
