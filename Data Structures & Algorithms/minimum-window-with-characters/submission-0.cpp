class Solution {
public:
    string minWindow(string s, string t) {
        if(s == "" || t == "") return "";
        
        vector<int> freq(128, 0);
        for(char &c : t) {
            freq[c]++;
        }

        int l = 0;
        int required = t.size();
        int startIdx = 0;
        int minWindow = INT_MAX;

        for(int r = 0; r<s.size(); ++r) {
            if(freq[s[r]] > 0) {
                required--;
            }
            freq[s[r]]--;

            while(required == 0) {
                if(r - l + 1 < minWindow) {
                    minWindow = r - l + 1;
                    startIdx = l;
                }
                
                freq[s[l]]++;
                if(freq[s[l]] > 0) {
                    required++;
                }
                l++;
            }
        }
        return minWindow == INT_MAX ? "" : s.substr(startIdx, minWindow); 
    }
};
