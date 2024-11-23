class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();    // Number of rows
        int n = box[0].size(); // Number of columns
        
        // Step 1: Apply gravity to each row
        for (int i = 0; i < m; ++i) {
            int emptyIndex = n - 1; // Pointer to the rightmost empty spot
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '*') {
                    // Reset emptyIndex when hitting an obstacle
                    emptyIndex = j - 1;
                } else if (box[i][j] == '#') {
                    // Move stone to the rightmost empty spot
                    box[i][j] = '.';
                    box[i][emptyIndex] = '#';
                    emptyIndex--;
                }
            }
        }
        
        // Step 2: Rotate the matrix 90 degrees clockwise
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotatedBox[j][m - 1 - i] = box[i][j];
            }
        }
        
        return rotatedBox;
    }
};
