class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]}); 
        }

        vector<int>distance(n, 1e9);

        distance[src] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        // stop, node dist
        pq.push({0, {src, 0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;
            for(auto iter: adj[node]){
                int adjnode = iter.first;
                int edw = iter.second;

                if(cost + edw < distance[adjnode] && stops <=k){
                    distance[adjnode] = cost + edw;
                    pq.push({stops+1, {adjnode, cost + edw }});
                }
            }
        }

        if(distance[dst] == 1e9) distance[dst] = -1;
        return distance[dst];
    }
};