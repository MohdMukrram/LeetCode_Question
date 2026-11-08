class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0,j=n-1;

        int mx = INT_MIN;

        while(i<j){
            mx = max(mx,min(height[i],height[j]) * (j-i));
            if(height[i] < height[j]) i++;
            else j--;
        }
        return mx;
    }
};