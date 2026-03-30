class Solution {
public:
    vector<int> cur;
    vector<vector<int>> res;
    void bt(int start, int n, int k) {
        if(cur.size() == k) {
            res.push_back(cur);
            return;
        }

        for(int i = start; i<=n; ++i) {
            cur.push_back(i);
            bt(i + 1, n, k);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        bt(1, n, k);
        return res;
    }
};