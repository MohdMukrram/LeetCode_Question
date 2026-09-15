class Solution {
public:
    int findMaxIdx(vector<vector<int>>& mat, int n , int m , int col){
        int maxvalue = -1;
        int index = -1;
        for(int i=0;i<n;i++){
            if(mat[i][col] > maxvalue){
                maxvalue = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m = mat[0].size();
        int lo=0;
        int hi=m-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int maxRowIdx = findMaxIdx(mat , n , m ,mid);
            int left = mid - 1 >= 0 ? mat[maxRowIdx][mid-1] : -1;
            int right = mid + 1 < m ? mat[maxRowIdx][mid+1] : -1;
            if(mat[maxRowIdx][mid] > left && mat[maxRowIdx][mid] > right){
                return {maxRowIdx , mid};
            }
            else if(mat[maxRowIdx][mid] < left) hi = mid-1;
            else lo = mid+1;
        }
        return {-1,-1};
    }
};