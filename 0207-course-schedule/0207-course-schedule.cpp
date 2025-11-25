class Solution {
public:
    bool dfs( int node,  vector<int>&visited, vector<vector<int>>&adj){
        visited[node] = 1;

        for(int neighbour: adj[node]){
            if(visited[neighbour] == 0){
                if(dfs(neighbour, visited, adj)) return true;
            } else if(visited[neighbour] == 1){
                return true;
            }
        }
        visited[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>visited(numCourses, 0);
        vector<vector<int>>adj(numCourses);

        for(auto &pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        for(int i=0; i<numCourses; i++){
            if(visited[i] == 0){
                if(dfs(i, visited, adj)) return false;
            }
        }
        return true;
    }
};