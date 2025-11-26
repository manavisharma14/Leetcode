class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        queue<int>q;
        vector<int>indegree(n);
        vector<vector<int>>adj(n);

        for(auto &pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        for(int u=0; u<n; u++){
            for(auto it: adj[u]){
                indegree[it]++;
            }
        }

        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            count++;

            for(auto v: adj[node]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return n == count;

    }
};