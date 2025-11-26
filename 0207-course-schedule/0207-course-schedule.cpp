class Solution {
public:

    bool dfs(int n, vector<vector<int>>& adj, vector<int>& visited){
        visited[n] = 1;

        for(int neighbour: adj[n]){
            if(visited[neighbour] == 0 && dfs(neighbour, adj, visited)) return true;
            if(visited[neighbour] == 1) return true ;
        }
        visited[n] = 2;
        return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>visited(numCourses, 0);
        vector<vector<int>>adj(numCourses);

        for(auto &pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        for(int i=0; i<numCourses; i++){
            if(visited[i] == 0 && dfs(i, adj, visited)) return false;
        }
        return true;
    }
};