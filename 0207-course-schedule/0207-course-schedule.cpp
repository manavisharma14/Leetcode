class Solution {
public:
    bool dfs(int i, vector<vector<int>>&adj, vector<int>&visited){
        if(visited[i] == 1){
            return false;
        }

        if(visited[i] == 2){
            return true;
        }
        
        visited[i] = 1;

        for(int next: adj[i]){
            if(!dfs(next, adj, visited)){
                return false;
            }
        }
        visited[i] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(auto &p: prerequisites){
            int course = p[0];
            int prerequisite = p[1];

            adj[prerequisite].push_back(course);
        }

        vector<int>visited(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(visited[i] == 0){
                if(!dfs(i, adj, visited)){
                    return false;
                }
            }
        }
        return true;
    }
};