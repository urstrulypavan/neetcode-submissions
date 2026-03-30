class Solution {
public:
    vector<int> cur;
    vector<vector<int>> res;
    vector<bool> used;

    void bt(vector<int>& nums) {
        if(cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }

        for(int i=0; i<nums.size(); ++i) {
            if(used[i]) continue;

            used[i] = true;
            cur.push_back(nums[i]);
            bt(nums);
            cur.pop_back();
            used[i] = false;
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {;
        res.clear();
        cur.clear();
        used.assign(nums.size(), false);

        bt(nums);
        return res;
    }
};
