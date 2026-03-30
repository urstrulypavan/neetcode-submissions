class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        if(dead.count("0000")) return -1;

        queue<string> q;
        q.push("0000"); 
        visited.insert("0000");

        int moves = 0;

        while(!q.empty()) {
            int size = q.size();

            for(int i=0; i<size; ++i) {
                string cur = q.front();
                q.pop();

                if(cur == target) return moves;
                for(int j=0; j<4; ++j) {
                    char original = cur[j];
                    cur[j] = (original == '9') ? '0' : original + 1;
                    if(!visited.count(cur) && !dead.count(cur)) {
                        q.push(cur);
                        visited.insert(cur);
                    }

                    cur[j] = (original == '0') ? '9' : original - 1;
                    if(!visited.count(cur) && !dead.count(cur)) {
                        q.push(cur);
                        visited.insert(cur);
                    }
                    cur[j] = original;
                }
            }
            moves++;
        }
        return -1;
    }
};