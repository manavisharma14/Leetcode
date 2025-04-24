class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> map;
        int sum = 0;
        int count = 0;
        map[0] = 1;

        for(int i = 0; i < n; i++) {
            sum += nums[i];

            // Removed: if(sum == k) count++; 
            // Instead, check if sum - k exists in the map

            int rem = sum - k;
            if (map.find(rem) != map.end()) {
                count += map[rem];
            }
            
            map[sum]++;
        }
        return count;
    }
};
