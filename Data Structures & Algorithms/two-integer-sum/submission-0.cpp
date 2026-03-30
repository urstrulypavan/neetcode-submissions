class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>prevMap;
        int n = nums.size();
        for(int i=0; i<n; ++i){
            int comp = target - nums[i];
            if(prevMap.count(comp)){
                return {prevMap[comp], i};
            } prevMap[nums[i]] = i;
        }
        return {};
    }
};
