class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int n = s.size();
        int l=0, r=0, res=0;
        int maxFreq = 0;
        while(r < n){
            count[s[r]]++;
            maxFreq = max(maxFreq, count[s[r]]);
            if((r-l+1) - maxFreq > k){
                count[s[l]]--;
                ++l;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};
