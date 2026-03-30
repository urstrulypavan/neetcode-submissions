class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return false;

        parent[py] = px;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);

        for(int i=0; i<=n; ++i) {
            parent[i] = i;
        }

        for(auto &edge : edges) {
            if(!unite(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};
