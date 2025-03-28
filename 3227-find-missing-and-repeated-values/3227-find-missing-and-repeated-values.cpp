class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n*n;
        vector<int>freq(N+1,0);

        int missing = -1;
        int repeated = -1;

        for(int i=0; i<n; i++){
            for(int num : grid[i]){
                freq[num]++;
            }
        }

        for(int i=1; i<=N; i++){
            if(freq[i] == 0){
                missing = i;
            }
            if(freq[i] == 2){
                repeated = i;
            }
        }
        return {repeated, missing};

    }
};