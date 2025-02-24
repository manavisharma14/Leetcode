class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minheap;
    int counter=0;

    for(int num: nums){
        minheap.push(num);
    }
    while(minheap.top() < k){
            long long x = minheap.top();
            minheap.pop();
            long long y = minheap.top();
            minheap.pop();
            long long newelement = (long long)(min(x,y)*2 + max(x,y));
            minheap.push(newelement);
            counter++;
        }
    return counter;

    }
};