class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> res;
        for(int num: nums) 
            mp[num]++;

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto [num, freq] : mp)
            bucket[freq].push_back(num);
        
        int n = bucket.size() - 1;

        for(int i = nums.size(); i > 0; i--) {
            for(auto elem: bucket[i]) {
                res.push_back(elem);
                k--;

                if (k == 0) return res;
            }
        }
        
        return res;
    }
};
