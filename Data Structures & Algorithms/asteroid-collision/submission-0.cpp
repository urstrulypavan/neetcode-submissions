class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        int write = 0;

        for(int& a : asteroids){
            bool alive = true;
            while(alive && write > 0 && a < 0 && asteroids[write - 1] > 0){

                int diff = a + asteroids[write - 1];
                    if(diff > 0){
                        alive = false;
                    }
                    else if(diff < 0){
                        --write;
                    }
                    else {
                        alive = false;
                        --write;
                    }
                
            }
            
            if(alive){
                asteroids[write++] = a;
            }
        }
        return vector<int>(asteroids.begin(), asteroids.begin() + write);
    }
};