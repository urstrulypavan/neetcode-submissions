class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    void bt(int start, vector<int>& candid, int remain) {
        if(remain == 0) {
            res.push_back(cur);
            return;
        }
        if(remain < 0) return;

        for(int i=start; i<candid.size(); ++i) {
            if(i > start && candid[i] == candid[i-1]) continue;
            if(candid[i] > remain) break;
            
            cur.push_back(candid[i]);
            bt(i + 1, candid, remain - candid[i]);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        bt(0, candidates, target);
        return res;
    }
};
