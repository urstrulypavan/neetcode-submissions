class Solution {
public:
    int helper(int start, int end, vector<int>& nums) {
        if(start == end) return nums[start];

        int rob1 = 0;
        int rob2 = 0;
        for(int i = start; i <= end; ++i) {
            int temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        return max(helper(0, n-2, nums), helper(1, n-1, nums));
    }
};
