class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n*n;
        vector<int>freq(N+1,0);
        int missing = -1;
        int repeated = -1;

        for(auto& row : grid){
            for(int num: row){
                freq[num]++;
            }
        }

        for(int i=1; i<=N; i++){
            if(freq[i] == 2){
                repeated = i;
            }

            if(freq[i] == 0){
                missing = i;
            }
        }
        return {repeated, missing};
    }
};