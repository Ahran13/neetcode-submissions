class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        if(nums.size() == 0) return 0;
        int ans = 1, k = 1;
        
        for(int num: nums) 
            mp[num]++;
        
        for(int num: nums) {
            if(!mp.count(num - 1)) {
                while(mp.count(num+k)) {
                    k++;
                    ans = max(ans, k);
                }
                k = 1;
            }
        }
        return ans;
    }
};
