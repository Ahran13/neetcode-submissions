class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<pair<int, int>> vec;
        vector<int> res;
        for(int num: nums) 
            mp[num]++;
        
        for(auto elem: mp) 
            vec.push_back(elem);
        
        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
            return a.second >= b.second;
        });

        for(int i = 0; i < k; i++) 
            res.push_back(vec[i].first);
        return res;
    }
};
