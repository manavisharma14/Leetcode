class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int,pair<int,int>>positionmap;

        vector<int>rowcount(m,0);
        vector<int>colcount(n,0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                positionmap[mat[i][j]] = {i,j};
            }
        }

        for(int i=0; i<arr.size(); i++){
            int val = arr[i];

            auto [row, col] = positionmap[val];

            rowcount[row]++;
            colcount[col]++;

            if(rowcount[row] == n || colcount[col] == m){
                return i;
            }
        }

        return -1; 
    }
};