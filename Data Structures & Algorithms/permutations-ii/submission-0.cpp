class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    void bt(vector<int>& nums, vector<bool>& used) {
        if(cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }

        for(int i = 0; i<nums.size(); ++i) {
            if(used[i]) continue;

            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            
            cur.push_back(nums[i]);
            used[i] = true;
            bt(nums, used);

            cur.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<bool> used(nums.size(), false);

        bt(nums, used);
        return res;
    }
};