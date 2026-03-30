class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n;){
            if(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
            else ++i;
        }

        for(int j=0; j<n; ++j){
            if(nums[j] != j+1) return j+1;
        }
        return n+1;
    }
};