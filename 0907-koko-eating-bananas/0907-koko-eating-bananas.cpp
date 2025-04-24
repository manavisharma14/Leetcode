class Solution {
public:
    int findmax(vector<int>& piles) {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calcutotalhours(vector<int>& piles, int hourly) {
        long long totalH = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalH += (piles[i] + hourly - 1) / hourly;
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findmax(piles);
        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalH = calcutotalhours(piles, mid);
            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};