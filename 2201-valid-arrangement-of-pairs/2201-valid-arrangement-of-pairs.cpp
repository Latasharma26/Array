class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;  // Adjacency list
        unordered_map<int, int> inDegree, outDegree;

        // Build graph and calculate in/out degrees
        for (auto& pair : pairs) {
            int u = pair[0], v = pair[1];
            graph[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }

        // Find start node for Eulerian path
        int start = pairs[0][0];  // Default start
        for (auto& [node, _] : graph) {
            if (outDegree[node] > inDegree[node]) {
                start = node;
                break;
            }
        }

        // Hierholzer's algorithm to find Eulerian path
        vector<int> eulerianPath;
        stack<int> stack;
        stack.push(start);

        while (!stack.empty()) {
            int node = stack.top();
            if (!graph[node].empty()) {
                int next = graph[node].back();
                graph[node].pop_back();
                stack.push(next);
            } else {
                eulerianPath.push_back(node);
                stack.pop();
            }
        }

        // Reverse the path to get correct order
        reverse(eulerianPath.begin(), eulerianPath.end());

        // Build the result from the Eulerian path
        vector<vector<int>> result;
        for (int i = 0; i < eulerianPath.size() - 1; ++i) {
            result.push_back({eulerianPath[i], eulerianPath[i + 1]});
        }

        return result;
    }
};
