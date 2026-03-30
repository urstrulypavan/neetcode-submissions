class Solution {
public:
    vector<string> res;
    void bt(string cur, int openCount, int closeCount, int n) {
        if(cur.size() == 2*n) {
            res.push_back(cur);
            return;
        }

        if(openCount < n) {
            bt(cur + '(', openCount+1, closeCount, n);
        }
        if(closeCount < openCount) {
            bt(cur + ')', openCount, closeCount+1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        bt("", 0, 0, n);
        return res;
    }
};
