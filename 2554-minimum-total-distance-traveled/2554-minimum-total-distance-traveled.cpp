class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort the robots and factories by their positions on the X-axis
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // Number of robots and factories
        int m = robot.size(), n = factory.size();
        
        // Initialize a large value for comparison
        const long long INF = 1e18;

        // DP table with size (m+1)x(n+1), initially set to INF
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, INF));
        dp[0][0] = 0; // No robots, no factories, cost is 0
        
        // Iterate over factories
        for (int j = 1; j <= n; ++j) {
            int factory_pos = factory[j-1][0]; // Position of the current factory
            int limit = factory[j-1][1];       // Limit of robots it can repair
            
            // Copy previous row's values as they are (ignoring current factory)
            for (int i = 0; i <= m; ++i) {
                dp[i][j] = dp[i][j-1];
            }
            
            // Process each robot for the current factory within its limit
            for (int i = 1; i <= m; ++i) {
                long long dist = 0;
                
                // Try to assign up to 'limit' robots to the current factory
                for (int k = 1; k <= limit && i - k >= 0; ++k) {
                    dist += abs(factory_pos - robot[i - k]); // Cumulative distance
                    
                    // Update dp to get the minimum distance so far
                    dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + dist);
                }
            }
        }
        
        // Result is the minimum distance for all robots with all factories available
        return dp[m][n];
    }
};