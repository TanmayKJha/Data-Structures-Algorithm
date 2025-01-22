class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> heights(m, vector<int>(n, -1)); // Initialize heights with -1
        queue<pair<int, int>> que;

        // Initialize water cells with height 0 and add them to the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    heights[i][j] = 0;
                    que.push({i, j});
                }
            }
        }

        // Direction vectors for moving in 4 directions
        int rowChange[] = {-1, 0, 1, 0};
        int colChange[] = {0, 1, 0, -1};

        // Perform BFS
        while (!que.empty()) {
            auto [row, col] = que.front();
            que.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = row + rowChange[i];
                int newCol = col + colChange[i];

                // Check if the new cell is valid and not visited
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] == -1) {
                    heights[newRow][newCol] = heights[row][col] + 1; // Increment height
                    que.push({newRow, newCol});
                }
            }
        }

        return heights;
    }
};
