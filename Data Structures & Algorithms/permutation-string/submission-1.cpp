class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int m = s1.size();
        int n = s2.size();
        sort(s1.begin(), s1.end());

        for(int i=0; i+m <= n; ++i){
            string subStr = s2.substr(i, m);
            sort(subStr.begin(), subStr.end());
            if(s1 == subStr) return true;
        }
        return false;
    }
};
