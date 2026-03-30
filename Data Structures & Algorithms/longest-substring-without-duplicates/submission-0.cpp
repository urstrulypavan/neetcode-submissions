class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0; i<n; ++i){
            vector<bool> visited(256, false);
            int c = 0;
            for(int j = i; j<n; ++j){
                if(visited[s[j]]) break;
                visited[s[j]] = true;
                c++;
            }
            count = max(count, c);
        }
        return count;
    }
};
