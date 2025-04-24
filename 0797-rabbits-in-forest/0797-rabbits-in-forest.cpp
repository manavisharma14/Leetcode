class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>map;
        int ans = 0;

        for(int num: answers){
            map[num]++;
        }

        for(auto &pair: map){
            int groupsize = pair.first + 1;
            int groupcount = pair.second;

            ans += ((groupcount + groupsize -1 )/groupsize)*groupsize;
        }
        return ans;
    }
};