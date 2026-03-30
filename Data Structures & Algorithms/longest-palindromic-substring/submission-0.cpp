class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;

        string lps = "";

        for(int i=1; i<s.size(); ++i) {
            // odd palindrome
            int low = i;
            int high = i;
            while(s[low] == s[high]) {
                low--;
                high++;
                if(low == -1 || high == s.size()) {
                    break;
                }
            }
            string palindrome = s.substr(low+1, high-low-1);
            if(lps.size() < palindrome.size()) {
                lps = palindrome;
            }

            // even palindrome
            low = i-1;
            high = i;
            while(s[low] == s[high]) {
                low--;
                high++;
                if(low == -1 || high == s.size()) {
                    break;
                }
            }
            palindrome = s.substr(low+1, high-low-1);
            if(lps.size() < palindrome.size()) {
                lps = palindrome;
            }
        }
        return lps;
    }
};
