class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& prerequisites) {
        vector<int>indegree(v,0);

        vector<vector<int>>adj(v);

        for(auto &pre : prerequisites){
            int prerequisite = pre[1];
            int course = pre[0];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int>q;

        for(int i=0; i<v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(topo.size() == v){
            return topo;
        }
        else {
            return {};
        }
    }
};