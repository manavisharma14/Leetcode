class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

        long long top_sum = 0;
        long long bottom_sum = 0;

        for(int i=0; i<grid[0].size(); i++){
            top_sum += grid[0][i];
        }

        long long result = LLONG_MAX; 

        for(int i=0; i<grid[0].size(); i++){
            top_sum -= grid[0][i];
            result = min(result, max(top_sum, bottom_sum));
            bottom_sum += grid[1][i];
        }



        
        return result;
    }
};