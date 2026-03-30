class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    void backtrack(int start, vector<int>& nums, int remaining) {
        if(remaining == 0) {
            res.push_back(cur);
            return;
        }
        if(remaining < 0) return;

        for(int i = start; i<nums.size(); ++i) {
            cur.push_back(nums[i]);
            backtrack(i, nums, remaining - nums[i]);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(0, nums, target);
        return res;
    }
};
