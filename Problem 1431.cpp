//1431. Kids With the Greatest Number of Candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();

        int total_candies = 0;
         vector<bool> result(n, false);

        for(int i=0; i<n; i++){
            total_candies = candies[i] + extraCandies;
            
            bool canBeGreatest = true;
            
            for(int j=0; j<n; j++){
                if(j!=i && (total_candies < candies[j])){
                canBeGreatest = false;
                break;
                }
            }
            result[i] = canBeGreatest;
 
        }
        return result;
    }

};