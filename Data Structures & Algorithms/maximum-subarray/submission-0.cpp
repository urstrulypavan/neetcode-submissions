class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int curSum = 0;
        for(int &x : nums) {
            curSum += x;
            maxSum = max(maxSum, curSum);

            if(curSum < 0) curSum = 0;
        }
        return maxSum;
    }
};
