class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top_sum = 0;    // Total points in the top row
        long long bottom_sum = 0; // Total points in the bottom row

        int i=0;
        for(int j=0; j<grid[0].size(); j++){
            top_sum += grid[i][j];
        }

        long long result = LLONG_MAX;

        for (int i = 0; i < grid[0].size(); i++) {
            top_sum -= grid[0][i];  // Remove current column's value from top_sum
            result = min(result, max(top_sum, bottom_sum)); // Minimize Robot 2's max points
            bottom_sum += grid[1][i];  // Add current column's value to bottom_sum
        }
        return result;
    }
};