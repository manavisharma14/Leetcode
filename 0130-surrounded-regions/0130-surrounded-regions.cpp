class Solution {
public:
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& board){
        visited[row][col] = 1;
        int m = board.size();
        int n = board[0].size();

        for(int i=0 ;i<4; i++){
            int dx = row + directions[i][0];
            int dy = col + directions[i][1];

            if(dx>=0 && dx<m && dy>=0 && dy<n && board[dx][dy] == 'O' && !visited[dx][dy]){
                visited[dx][dy] = 1;
                dfs(dx, dy, visited, board);
            }
        }

    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>>visited(m, vector<int>(n,0));

        // traverse first and last row
        for(int j=0; j<n; j++){
            // first row
            if(!visited[0][j] && board[0][j] == 'O'){
                dfs(0, j , visited, board);
            }
            //second row
            if(!visited[m-1][j] && board[m-1][j] == 'O'){
                dfs(m-1, j , visited, board);
            }
        }

        // traverse first col and last col
        for(int i=0; i<m; i++){
            //first col
            if(!visited[i][0] && board[i][0] == 'O'){
                dfs(i, 0, visited, board);
            }

            // last col
            if(!visited[i][n-1] && board[i][n-1] == 'O'){
                dfs(i, n-1, visited, board);
            }
        }

        for(int i=0 ;i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

    }
};