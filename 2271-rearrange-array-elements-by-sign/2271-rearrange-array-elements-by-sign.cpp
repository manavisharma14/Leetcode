class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       vector<int>positive;
       vector<int>negative;

        for(int num: nums){
            if(num>0){
                positive.push_back(num);
            }
            else if(num<0){
                negative.push_back(num);
            }
        }

        int posidx=0, negidx=0;
        vector<int>result;

        for(int i=0; i<nums.size(); i++){
            if(i%2 == 0){
                result.push_back(positive[posidx++]);
            }
            else {
                result.push_back(negative[negidx++]);
            }
        }
        return result;
    }
};