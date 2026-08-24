class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        int res = n;
        vector<double> time;
        stack<double> st;
        for(int i = 0; i < n; i++) 
            time.push_back((double) (target - position[i])/speed[i]);
        map<int, double, greater<int>> pt;
        
        for(int i = 0; i < n; i++) {
            pt[position[i]] = time[i];
        }

        for(pair<int,double> duo: pt) {
            if(!st.empty() && st.top() >= duo.second) {
                res--;
                continue;
            }
            else
                st.push(duo.second);
        }
        return res;
    }
};
