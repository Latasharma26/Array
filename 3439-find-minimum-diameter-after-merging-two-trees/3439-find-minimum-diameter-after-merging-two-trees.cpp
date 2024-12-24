class Solution {
public:
    int findDiameter(vector<vector<int>>& edges, int n) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        auto bfs = [&](int start) {
            vector<int> dist(n, -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;
            int farthestNode = start;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int neighbor : graph[curr]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[curr] + 1;
                        q.push(neighbor);
                        farthestNode = neighbor;
                    }
                }
            }
            return make_pair(farthestNode, dist[farthestNode]);
        };

        auto [nodeA, _] = bfs(0);
        auto [nodeB, diameter] = bfs(nodeA);
        return diameter;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        int diameter1 = findDiameter(edges1, n);
        int diameter2 = findDiameter(edges2, m);

        // Minimize the combined diameter:
        return max(diameter1, max(diameter2, (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1));
    }
};
