class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int prev1 = 1;
        int prev2 = 1;

        for(int i=2; i<=s.size(); ++i) {
            int cur = 0;
            if(s[i-1] != '0') 
                cur += prev1;

            int two = stoi(s.substr(i-2, 2));
            if(two >= 10 && two <= 26) 
                cur += prev2;
            
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
