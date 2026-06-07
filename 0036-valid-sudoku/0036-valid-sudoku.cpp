class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>>rows(9);
        vector<unordered_set<int>>cols(9);
        vector<unordered_set<int>>boxes(9);

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                char c = board[i][j];
                int box = (i/3)*3 + (j/3);

                if(c == '.') continue;

                if((rows[i].find(c) != rows[i].end()) ||
                    cols[j].find(c) != cols[j].end() ||
                    boxes[box].find(c) != boxes[box].end()) return false;
                
                rows[i].insert(c);
                cols[j].insert(c);
                boxes[box].insert(c);
            }
        }
        return true;
    }
};