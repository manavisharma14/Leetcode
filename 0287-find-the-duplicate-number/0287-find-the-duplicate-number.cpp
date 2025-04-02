class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    
        int n = nums.size()-1;
        int result = 0;

        for(int bit=0; bit<32; bit++){
            int mask = (1<<bit);
            int countinnums = 0;
            int countinrange = 0;

            for(int num : nums){
                if(num & mask) countinnums++;
            }

            for(int i=0; i<=n; i++){
                if(i & mask) countinrange++;
            }

            if(countinnums > countinrange){
                result |= mask;
            }
        }
        return result;
        
    }
};