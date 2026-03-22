class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++){
            unordered_set<int>rowSet;
            unordered_set<int>colSet;

            for(int j=0; j<n; j++){
                // check row
                if(rowSet.count(matrix[i][j])) return false;
                rowSet.insert(matrix[i][j]);

                // check col
                if(colSet.count(matrix[j][i])) return false;
                colSet.insert(matrix[j][i]);
            }
        }
        return true;
    }
};