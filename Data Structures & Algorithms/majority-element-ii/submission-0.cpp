class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int>freq;
        int n = nums.size();

        for(int num : nums){
            freq[num]++;
        }

        vector<int>res;
        for(auto &[key, value] : freq){
            if(value > n/3){
                res.push_back(key);
            }
        }
        return res;
    }
};