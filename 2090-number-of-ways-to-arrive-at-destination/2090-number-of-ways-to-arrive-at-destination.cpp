class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;


        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }


        vector<long long> distance(n, LLONG_MAX);

        vector<long long>ways(n,0);
        int mod = (int)(1e9+7);
        ways[0] = 1;

        distance[0] = 0;
        pq.push({0,0});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            long long dist = it.first;
            int node = it.second;

            for(auto iter: adj[node]){
                int adjnode = iter.first;
                int t = iter.second;

                if (dist > distance[node]) continue;


                long long newDist = distance[node] + t;
                if (newDist < distance[adjnode]) {
                    distance[adjnode] = newDist;
                    ways[adjnode] = ways[node];
                    pq.push({newDist, adjnode});
                }


                else if(distance[adjnode] == newDist) {
                    ways[adjnode] = (ways[node] + ways[adjnode]) % mod;
                }

            }
        }
        return ways[n - 1] % mod ;
    }
};