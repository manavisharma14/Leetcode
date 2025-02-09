class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int>freq;
        int n = nums.size();
long long totalpairs = (1LL * n * (n - 1)) / 2;

        long long goodpairs = 0;

        for(int i=0; i<n; i++){
            int diff = nums[i] - i;
            goodpairs += freq[diff];
            freq[diff]++;
        }
        
        return totalpairs - goodpairs;
    }
};