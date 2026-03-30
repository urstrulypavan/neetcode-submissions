class Solution {
public:
    int m, n;
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void bfs( queue<pair<int, int>> &q, vector<vector<bool>> &visited, vector<vector<int>>& heights) {
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                for(auto [dx, dy] : dirs) {
                    int ni = r + dx;
                    int nj = c + dy;

                    if(ni < 0 || nj < 0 || ni >=m || nj >= n)
                        continue;
                    if(visited[ni][nj]) 
                        continue;
                    if(heights[ni][nj] < heights[r][c])
                        continue;

                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
            
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        queue<pair<int, int>> pq, aq; 
        vector<vector<bool>>pacific(m, vector<bool>(n, false));
        vector<vector<bool>>atlantic(m, vector<bool>(n, false));

        for(int i=0; i<m; ++i) {
            pq.push({i, 0});
            pacific[i][0] = true;
        }
        for(int j=0; j<n; ++j) {
            pq.push({0, j});
            pacific[0][j] = true;
        }

        for(int i=0; i<m; ++i) {
            aq.push({i, n-1});
            atlantic[i][n-1] = true;
        }
        for(int j=0; j<n; ++j) {
            aq.push({m-1, j});
            atlantic[m-1][j] = true;
        }

        bfs(pq, pacific, heights);
        bfs(aq, atlantic, heights);

        vector<vector<int>> res;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }
};
