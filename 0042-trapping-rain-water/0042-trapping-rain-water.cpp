class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l_mx = height[0];
        vector<int> l_max(n,0);

        for(int i=1;i<n;i++){
            l_max[i] = l_mx;
            l_mx = max(l_mx,height[i]);
        }

        int r_mx = height[n-1];
        vector<int> r_max(n,0);

        for(int i=n-2;i>=0;i--){
            r_max[i] = r_mx;
            r_mx = max(r_mx,height[i]);
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            int sum = min(l_max[i],r_max[i]) - height[i];
            
            if(sum >=0) ans += sum;
        }
        return ans;
    }
};