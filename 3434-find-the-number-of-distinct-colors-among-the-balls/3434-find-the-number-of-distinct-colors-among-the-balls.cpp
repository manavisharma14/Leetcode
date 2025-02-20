class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>map1; // ball->color
        unordered_map<int,int>map2; // color->freq

        vector<int>result;

        for(auto query: queries){
            int ball = query[0];
            int color = query[1];

            if(map1.find(ball) != map1.end()){
                int oldcolor = map1[ball];
                map2[oldcolor]--;
                if(map2[oldcolor] == 0){
                    map2.erase(oldcolor);
                }
            }

            // assign new color

            map1[ball] = color;
            map2[color]++;

            result.push_back(map2.size());
        }
        return result;
    }
};