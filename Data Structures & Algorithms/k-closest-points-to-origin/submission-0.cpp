class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for(auto& p : points) {
            int dist = p[0]*p[0] + p[1]*p[1];
            maxHeap.push({dist, {p[0], p[1]}});
        }

        while(maxHeap.size() > k) {
            maxHeap.pop();
        }

        vector<vector<int>> ans;
        while(!maxHeap.empty()) {
            auto pt = maxHeap.top().second;
            ans.push_back({pt.first, pt.second});
            maxHeap.pop();
        }

        return ans;
    }
};
