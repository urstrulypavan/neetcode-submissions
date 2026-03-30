class Solution {
public:
    int n, m;
    vector<vector<bool>> visited;
    bool dfs(int i, int j, int k, vector<vector<char>>& board, string word) {
        if(k == word.size()) return true;
        if(i < 0 || j < 0 || i >= n || j >= m) {
            return false;
        }
        if(visited[i][j]) return false;
        if(board[i][j] != word[k]) return false;

        visited[i][j] = true;
        bool found = dfs(i+1, j, k+1, board, word) ||
               dfs(i-1, j, k+1, board, word) ||
               dfs(i, j+1, k+1, board, word) ||
               dfs(i, j-1, k+1, board, word);
        visited[i][j] = false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        visited.assign(n, vector<bool>(m, false));

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(dfs(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
};
