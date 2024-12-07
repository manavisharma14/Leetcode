class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;

        for(int num: nums){
            map[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for(auto i = map.begin(); i!=map.end(); i++){
            minHeap.push({i->second, i->first});

            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
            vector<int>result;
            
            while(minHeap.size()){
                result.push_back(minHeap.top().second);
                minHeap.pop();
            }
        
        return result;
    }
};