class Solution {
public:
    vector<vector<string>> res;
    int N;
    vector<string> board;
    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;

    void bt(int row) {
        if(row == N) {
            res.push_back(board);
            return;
        }

        for(int c=0; c<N; ++c) {
            if(col[c] || diag1[row - c + N - 1] || diag2[row + c]) continue;

            col[c] = diag1[row - c + N - 1] = diag2[row + c] = true;
            board[row][c] = 'Q';
            bt(row + 1);

            board[row][c] = '.';
            col[c] = diag1[row - c + N - 1] = diag2[row + c] = false;
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        board.assign(n, string(n, '.'));
        col.assign(n, false);
        diag1.assign(2*n-1, false);
        diag2.assign(2*n-1, false);

        bt(0);
        return res;
    }
};
