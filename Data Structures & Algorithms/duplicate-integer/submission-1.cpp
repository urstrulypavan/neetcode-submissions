class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int>freq;
        for(auto &n : nums){
            freq[n]++;
        }
        for(int i=0; i<freq.size(); ++i){
            if(freq[nums[i]] > 1) return true;
        }
        return false;
    }
};