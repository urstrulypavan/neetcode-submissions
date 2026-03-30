class Solution {
public:
    vector<int> cur;
    vector<vector<int>> res;
    void bt(int i, int n, int k) {
        if(cur.size() == k) {
            res.push_back(cur);
            return;
        }
        if(i > n) return; 

        cur.push_back(i);
        bt(i+1, n, k);
        cur.pop_back();
        bt(i+1, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        bt(1, n, k);
        return res;
    }
};