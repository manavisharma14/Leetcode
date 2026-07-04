class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board.size(); j++){
                if(board[i][j] == '.') continue;
                if(rows[i].find(board[i][j]) != rows[i].end()) return false;
                else rows[i].insert(board[i][j]);
                
                if(cols[j].find(board[i][j]) != cols[j].end()) return false;
                else cols[j].insert(board[i][j]);

                int box = (i/3)*3 + (j/3);
                if(boxes[box].find(board[i][j]) != boxes[box].end()) return false;
                else boxes[box].insert(board[i][j]);
            }
        }
        return true;
    }
};