class Solution {
public:
    int m, n, oldColor;

    void dfs(int i, int j, int color, vector<vector<int>>& image) {
        if(i<0 || j<0|| i >= m || j>=n|| image[i][j] != oldColor) {
            return;
        }

        image[i][j] = color;
        dfs(i+1, j, color, image);
        dfs(i-1, j, color, image);
        dfs(i, j+1, color, image);
        dfs(i, j-1, color, image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        oldColor = image[sr][sc];

        if(oldColor == color) return image;

        dfs(sr, sc, color, image);
        return image;
    }
};