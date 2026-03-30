class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    void bt(int start, vector<int>& nums) {
       
        res.push_back(cur);
        
        for(int i=start; i<nums.size(); ++i) {
            if(i > start && nums[i] == nums[i-1]) continue;

            cur.push_back(nums[i]);
            bt(i + 1, nums);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        bt(0, nums);
        return res;
    }
};
