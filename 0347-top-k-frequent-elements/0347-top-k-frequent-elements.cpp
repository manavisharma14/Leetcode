class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        vector<int>result;
        priority_queue<pair<int,int>>pq;

        for(int num: nums){
            freq[num]++;
        }

        for(auto& it: freq){
            pq.push({it.second, it.first});
        }

        while(k > 0 && !pq.empty()){
            result.push_back(pq.top().second); pq.pop(); k--;
        }
        return result;
    }
};