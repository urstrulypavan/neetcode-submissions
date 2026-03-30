class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for(int i=0; i<position.size(); ++i){
            pair.push_back({position[i], speed[i]});
        }

        sort(pair.rbegin(), pair.rend());

        vector<double> stack; //stores time
        for(int i=0; i<pair.size(); ++i){
            stack.push_back((double)(target-pair[i].first)/pair[i].second);
            if(stack.size() >= 2 && stack.back() <= stack[stack.size()-2]){
                stack.pop_back();
            }
        }

        return stack.size();

    }
};
