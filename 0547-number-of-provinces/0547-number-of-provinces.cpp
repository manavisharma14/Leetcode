class Solution {
public:

    void dfs(int node, vector<int>&visited, vector<vector<int>>& isConnected ){
        visited[node] = 1;

        for(int it = 0; it < isConnected[node].size(); ++it){
            if(isConnected[node][it] == 1 && !visited[it]){

                dfs(it, visited, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int result = 0;
        int v = isConnected.size();
        vector<int>visited(v,0);
        for (int i = 0; i < v; ++i) {
            if (!visited[i]) {  
                result++; 
                dfs(i, visited, isConnected);  
            }
        }

        return result;
    }
};