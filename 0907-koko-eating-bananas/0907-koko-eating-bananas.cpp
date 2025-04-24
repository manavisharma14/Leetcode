class Solution {
public:

    int findmax(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i=0; i<piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long func(vector<int>&piles, int hourly){
        int n = piles.size();
        long long totalhours = 0;
        for(int i=0; i<n; i++){
            totalhours += (piles[i] + hourly - 1)/hourly;
        }
        return totalhours;

    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findmax(piles);

        while(low<=high){
            int mid = low + ((high-low) >> 1);
            long long total = func(piles, mid);

            if(total <= h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return low;
    }
};
