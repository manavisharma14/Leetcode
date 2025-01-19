class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>map;
        map[0]=1;
        
        int current_sum = 0, count=0; 

        for(int num : nums){
            current_sum += num;

            if(map.find(current_sum - k) != map.end()){
                count += map[current_sum - k];
            }

            map[current_sum]++;
        }
        return count;
    }
};
