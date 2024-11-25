
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        string target = "123450";
        
        // Convert the board to a string
        for (const auto& row : board) {
            for (const auto& cell : row) {
                start += to_string(cell);
            }
        }
        
        // Define the possible moves for each index (0-based)
        vector<vector<int>> moves = {
            {1, 3},    // index 0
            {0, 2, 4}, // index 1
            {1, 5},    // index 2
            {0, 4},    // index 3
            {1, 3, 5}, // index 4
            {2, 4}     // index 5
        };
        
        // BFS setup
        queue<pair<string, int>> q; // {board configuration, move count}
        unordered_set<string> visited;
        q.push({start, 0});
        visited.insert(start);
        
        while (!q.empty()) {
            auto [current, moves_count] = q.front();
            q.pop();
            
            // If the target is reached
            if (current == target) return moves_count;
            
            // Find the index of '0'
            int zero_pos = current.find('0');
            
            // Try all possible moves
            for (int next_pos : moves[zero_pos]) {
                string next_state = current;
                swap(next_state[zero_pos], next_state[next_pos]);
                
                if (visited.find(next_state) == visited.end()) {
                    q.push({next_state, moves_count + 1});
                    visited.insert(next_state);
                }
            }
        }
        
        // If the target state is not reachable
        return -1;
    }
};