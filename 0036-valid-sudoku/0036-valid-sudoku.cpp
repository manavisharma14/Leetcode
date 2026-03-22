class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>rowset[9];
        unordered_set<char>colset[9];
        unordered_set<char>boxset[9];

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char c = board[i][j];
                if(c == '.') continue;

                if(rowset[i].count(c)) return false;
                rowset[i].insert(c);

                if(colset[j].count(c)) return false;
                colset[j].insert(c);

                int boxindex = i/3 * 3 + j/3;
                if(boxset[boxindex].count(c)) return false;
                boxset[boxindex].insert(c);
            }
        }
        return true;

    }
};