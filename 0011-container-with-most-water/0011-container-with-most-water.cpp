class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int n = height.size();
        int area = 0;

        int left = 0;
        int right = n-1;

        while(left < right){
            area = abs((right-left)* min(height[left], height[right]));
            maxarea = max(area, maxarea);
            if(height[left] > height[right]){
                right--;
            } else {
                left ++;
            }
        }
        return maxarea;
    }
};