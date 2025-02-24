class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited){
        visited[node] = 1;

        for(int i=0; i<isConnected.size(); i++){
            if(!visited[i] && isConnected[node][i]){
                dfs(i, isConnected, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        int count=0;
        vector<int>visited(v);

        for(int i=0; i<v; i++){
            if(!visited[i]){
                count++;
                dfs(i, isConnected, visited);
            }
        }
        return count;
    }
};