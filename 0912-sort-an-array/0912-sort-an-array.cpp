class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        int n = nums.size();
        vector<int>res;

        for(int i=0; i<n; i++){
            minHeap.push(nums[i]);
        }

        while(!minHeap.empty()){
            res.push_back(minHeap.top());
            minHeap.pop();
        }
        return res;
        
    }
};