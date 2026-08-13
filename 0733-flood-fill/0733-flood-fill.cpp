class Solution {
public:
    void dfs(int r, int c, int n, int m, vector<vector<int>>& image, vector<vector<bool>>& vis, int newColor, int oldColor){
        vis[r][c] = true;
        image[r][c] = newColor;

        //Up
        if(r-1 >= 0 && !vis[r-1][c] && image[r-1][c] == oldColor){
            dfs(r-1, c, n, m, image, vis, newColor, oldColor);
        }
        //Down
        if(r+1 < n && !vis[r+1][c] && image[r+1][c] == oldColor){
            dfs(r+1, c, n, m, image, vis, newColor, oldColor);
        }
        // left
        if(c-1 >= 0 && !vis[r][c-1] && image[r][c-1] == oldColor){
            dfs(r, c-1, n, m, image, vis, newColor, oldColor);
        }
        // right
        if(c-1 < m && !vis[r][c+1] && image[r][c+1] == oldColor){
            dfs(r, c+1, n, m, image, vis, newColor, oldColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m  = image[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dfs(sr, sc, n, m, image, vis, color, image[sr][sc]);

        return image;
    }
};