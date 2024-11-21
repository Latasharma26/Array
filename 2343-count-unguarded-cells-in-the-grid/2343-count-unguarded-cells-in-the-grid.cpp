class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Create a grid to represent the cells
        vector<vector<int>> grid(m, vector<int>(n, 0));
        int res = m * n - guards.size() - walls.size();

        // Mark walls with 1
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 1;
        }

        // Mark guards with 2
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }

        // Deduct the number of cells guarded by all guards
        for (auto& guard : guards) {
            res -= fill(grid, guard);
        }

        return res;
    }

private:
    int fill(vector<vector<int>>& grid, vector<int>& guard) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        // Directions for up, right, down, left
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (auto& dir : directions) {
            int i = guard[0];
            int j = guard[1];
            while (i + dir[0] >= 0 && i + dir[0] < m && 
                   j + dir[1] >= 0 && j + dir[1] < n && 
                   grid[i + dir[0]][j + dir[1]] != 1 && 
                   grid[i + dir[0]][j + dir[1]] != 2) {
                // If the cell is empty, mark it as guarded and increment count
                if (grid[i + dir[0]][j + dir[1]] == 0) {
                    count++;
                }
                grid[i + dir[0]][j + dir[1]] = 3; // Mark as guarded
                i += dir[0];
                j += dir[1];
            }
        }

        return count;
    }
};
