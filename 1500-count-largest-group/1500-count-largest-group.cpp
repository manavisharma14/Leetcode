class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int>groupcount;

        vector<int>sum;

        for(int i=1; i<=n; i++){
            int temp = i;
            int s = 0;
            while(temp){
                
                s += temp%10;
                temp/=10;
            }
            groupcount[s]++;
            sum.push_back(s);
        }

        int maxsize = 0;
        for(auto &pair: groupcount){
            maxsize = max(maxsize, pair.second);
        }

        int count = 0;
        for(auto &pair: groupcount){
            if(pair.second == maxsize) count++;
        }

        return count;
    }
};