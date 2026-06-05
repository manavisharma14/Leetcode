class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>>pq;
        vector<int>ans;

        for(int x: nums){
            pq.push(x);
        }

        while(!pq.empty()){
            ans.push_back(pq.top());    
            pq.pop();
        }
        return ans;
    }
};