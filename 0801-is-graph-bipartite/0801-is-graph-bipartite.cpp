class Solution {
public:

    bool dfs(int node, int col, vector<int>&color, vector<int>& visited, vector<vector<int>>& graph){
        visited[node] = 1;
        color[node] = col;

        for(auto it : graph[node]){
            if(!visited[it]){
                if(dfs(it, !col, color, visited, graph) == false)
                return false;
            }
            else if(color[it] == col){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int>color(v,-1);
        vector<int>visited(v,0);

        for(int i=0; i<v; i++){
            if(!visited[i]){
                if(dfs(i, 0, color, visited, graph) == false) return false;
            }
        }
        return true;
    }
};