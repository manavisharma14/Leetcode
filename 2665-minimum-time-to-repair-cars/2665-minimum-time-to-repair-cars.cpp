class Solution {

private:
    bool assign(vector<int>& ranks, long long &mid, int &cars){
        long long count = 0;
        for(long long rank : ranks){
            count += sqrt(mid/rank);
        }
        return count >= cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars;

        long long ans = 0;

        while(left<=right){
            long long mid = left + (right-left)/2;
            if(assign(ranks, mid, cars)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};