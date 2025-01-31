class Solution {
public:

    void dfs(vector<vector<int>>& isConnected, int node, vector<int> &visited){
        visited[node] = 1;

        for(int it=0; it<isConnected[node].size(); ++it){
            if(isConnected[node][it] == 1 && !visited[it]){
                dfs(isConnected, it, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int>visited(v,0);
        int count=0;

        for(int i=0; i<v; i++){
            if(!visited[i]){
                count++;
                dfs(isConnected, i, visited);
            }
        }
        return count;
    }
};