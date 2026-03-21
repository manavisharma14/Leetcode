class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::priority_queue<int, vector<int>, greater<int>>pq;
        vector<int>ans;

        for(int num: nums){
            pq.push(num);
        }

        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};