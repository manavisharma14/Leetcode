class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int totalbusy = 0;
        int currstart = meetings[0][0];
        int currend = meetings[0][1];

        for(int i=1; i<meetings.size(); i++){
            int start = meetings[i][0];
            int end = meetings[i][1];

            if (start <= currend){
                currend = max(end, currend);
                start = min(start, currstart);
            }

            else{
                totalbusy += currend - currstart + 1;
                currstart = start;
                currend = end;
            }
        }

        totalbusy += currend - currstart + 1;
        return days-totalbusy;
    }
};