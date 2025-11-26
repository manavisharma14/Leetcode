class Solution {
public:

    bool dfs(int n, vector<int>&visited, vector<vector<int>>&adj){
        visited[n] = 1;
        for(int neighbour : adj[n]){
            if(visited[neighbour] == 1) { return true; }
            if(visited[neighbour] == 0 && dfs(neighbour, visited, adj)) return true;
        }
        visited[n] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int>visited(numCourses, 0);
        vector<vector<int>>adj(numCourses);

        for( auto &pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        for(int i=0 ;i<numCourses; i++){
            if(dfs(i, visited, adj)) return false;
        }
    return true;
    }
};