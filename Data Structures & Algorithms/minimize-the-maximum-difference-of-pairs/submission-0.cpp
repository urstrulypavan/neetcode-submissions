class Solution {
public:
    bool isValid(int threshold, vector<int>& nums, int p) {
        int cnt = 0;
        for(int i=0; i<nums.size()-1;) {
            if(abs(nums[i] - nums[i+1]) <= threshold) {
                cnt++;
                i+=2;
            } else i++;
        }
        if(cnt >= p) return true;
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int l = 0, r = pow(10, 9);
        int res = pow(10, 9);

        while(l <= r) {
            int mid = l+(r-l)/2;
            if(isValid(mid, nums, p)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};