class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        int res = 0;
        double max_time = 0.0;
        map<int, double, greater<int>> pt;
        
        for(int i = 0; i < n; i++) {
            double time = (double) (target - position[i])/speed[i];
            pt[position[i]] = time;
        }

        for(pair<int,double> duo: pt) {
            if(max_time < duo.second) {
                res++;
                max_time = duo.second;
            }
        }
        return res;
    }
};
