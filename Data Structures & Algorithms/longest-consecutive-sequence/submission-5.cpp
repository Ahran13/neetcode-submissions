class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp, visited;
        if(nums.size() == 0) return 0;
        int ans = 1, k = 1;
        
        for(int num: nums) 
            mp[num]++;
        
        for(int num: nums) {
            if(mp[num - 1] < 1) {
                while(mp[num + k] >= 1 && !visited[num + k]) {
                    visited[num + k] = 1;
                    k++;
                    ans = max(ans, k);
                }
                k = 1;
            }
        }
        return ans;
    }
};
