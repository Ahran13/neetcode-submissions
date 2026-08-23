class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> temp;
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            while(!temp.empty() && temperatures[i] > temperatures[temp.top()]) {
                res[temp.top()] = i - temp.top();
                temp.pop();
            }
            temp.push(i);
        }
        return res;
    }
};
