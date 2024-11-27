class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Adjacency list for the graph
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < n - 1; ++i) {
            graph[i].emplace_back(i + 1, 1); // Initial roads with weight 1
        }
        
        vector<int> result;
        
        // Function to find the shortest path using Dijkstra's algorithm
        auto dijkstra = [&](int src, int dest) -> int {
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            dist[src] = 0;
            pq.emplace(0, src);
            
            while (!pq.empty()) {
                auto [currDist, node] = pq.top();
                pq.pop();
                
                if (currDist > dist[node]) continue;
                
                for (auto& [neighbor, weight] : graph[node]) {
                    if (dist[node] + weight < dist[neighbor]) {
                        dist[neighbor] = dist[node] + weight;
                        pq.emplace(dist[neighbor], neighbor);
                    }
                }
            }
            
            return dist[dest];
        };
        
        // Process each query
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            graph[u].emplace_back(v, 1); // Add the new road
            
            // Recalculate shortest path
            int shortestPath = dijkstra(0, n - 1);
            result.push_back(shortestPath);
        }
        
        return result;
    }
};