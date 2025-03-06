class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, pair<int,int>>positionmap;

        vector<int> row_count(m, 0); // Count marked cells in each row
        vector<int> col_count(n, 0); // Count marked cells in each column

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                positionmap[mat[i][j]] = {i,j};
            }
        }

        for(int i=0; i<arr.size(); i++){
            int val = arr[i];

            auto [row,col] = positionmap[val];

            row_count[row]++;
            col_count[col]++;

            if (row_count[row] == n || col_count[col] == m) {
                return i;
            }
        }

        return -1; 
    }
};