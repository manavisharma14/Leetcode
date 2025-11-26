class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<int>indegree(numCourses);
        vector<vector<int>>adj(n);
        for(auto &pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        for(int u=0; u<n; u++){
            for(int v: adj[u]){
                indegree[v]++;
            }
        }
        queue<int>q;
        for(int i=0 ;i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;

            for(int v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return numCourses == count;

    }
};