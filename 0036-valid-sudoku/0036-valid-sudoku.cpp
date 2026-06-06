class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>>rows(9);
        vector<unordered_set<char>>cols(9);
        vector<unordered_set<char>>boxes(9);

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                int c = board[i][j];
                int box = (i / 3) * 3 + (j / 3);
                if(c== '.') continue;
                if(rows[i].count(c) ||
                    cols[j].count(c) ||
                    boxes[box].count(c)) return false;

                rows[i].insert(c);
                cols[j].insert(c);
                boxes[box].insert(c);
            }
        }
        return true;
    }
};