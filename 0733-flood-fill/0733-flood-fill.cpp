class Solution {
public:
    void solve(vector<vector<int>>& image, int sr, int sc, int prevcolor, int color, vector<vector<int>>& vis){
        int n = image.size();
        int m = image[0].size();
        if (sr < 0 || sr >= n || sc < 0 || sc >= m) return;

        if (vis[sr][sc] || image[sr][sc] != prevcolor) return;

        vis[sr][sc] = 1;
        image[sr][sc] = color;
        
        solve(image,sr,sc+1,prevcolor,color,vis);
        solve(image,sr,sc-1,prevcolor,color,vis);
        solve(image,sr+1,sc,prevcolor,color,vis);
        solve(image,sr-1,sc,prevcolor,color,vis);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        solve(image,sr,sc,image[sr][sc] ,color,vis);

        return image;
    }
};