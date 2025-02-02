class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;

        queue<pair<int, int>> q;

        // Enqueue all rotten oranges initially
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        // Directions array for 4 directions (down, up, right, left)
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // Perform BFS
        while (!q.empty()) {
            int size = q.size();
            bool rotten = false;  // Flag to check if any fresh orange rots in this level
            
            // Process all rotten oranges at this level
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                int r = node.first;
                int c = node.second;

                // Check all 4 directions for fresh oranges
                for (int j = 0; j < 4; j++) {
                    int dx = r + directions[j][0];
                    int dy = c + directions[j][1];

                    // Check bounds and if the adjacent orange is fresh
                    if (dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy] == 1) {
                        grid[dx][dy] = 2;  // Rot the fresh orange
                        q.push({dx, dy});
                        rotten = true;  // Mark that we rotted an orange
                    }
                }
            }

            // If any orange rotted in this level, increment time
            if (rotten) {
                time++;
            }
        }

        // After BFS, check if there are any fresh oranges left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;  // If there's any fresh orange left, return -1
                }
            }
        }

        return time;  // Return total time taken for all oranges to rot
    }
};
