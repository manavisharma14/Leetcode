class Solution {
public:
    int digitsum(int num){
        int sum = 0;
        while(num>0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        int maxsum = -1;
        unordered_map<int,int>mp;
        
        for(int num: nums){
            int sumofdigits = digitsum(num);
            if(mp.find(sumofdigits) != mp.end()){
                maxsum = max(maxsum, mp[sumofdigits] + num);
                 mp[sumofdigits] = max(mp[sumofdigits], num); 
            }
            else {
                mp[sumofdigits] = num;
            }
        }
        return maxsum;
    }
};