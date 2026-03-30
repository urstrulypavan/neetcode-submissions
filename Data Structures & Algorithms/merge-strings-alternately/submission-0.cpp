class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = min(word1.size(), word2.size());
        string large = word1.size() >= word2.size() ? word1 : word2;
        string result = "";
        for(int i=0; i<n; ++i){
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }
        result += large.substr(n);
        return result;
    }
};