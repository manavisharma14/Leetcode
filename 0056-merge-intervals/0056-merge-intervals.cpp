class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>>merged;

        int currstart = intervals[0][0];
        int currend = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start<=currend){
                currend = max(currend, end);
            }
            else{
                // store and sepeate 2 intervals
                merged.push_back({currstart, currend});
                currstart = start;
                currend = end;            
            }
        }

        merged.push_back({{currstart, currend}});
        return merged;
    }
};