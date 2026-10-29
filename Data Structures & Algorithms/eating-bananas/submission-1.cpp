class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxx = 0;
        for(auto &i: piles)
            maxx = max(maxx, i);

        int low = 1, high = maxx, ans = maxx;
        while(low <= high) {
            int k = low + (high - low) / 2;
            long long hours = 0;
            for(int &i: piles)
                hours += (i + 1LL * k - 1) / k;
            if (hours > h) 
                low = k + 1;
            else {
                ans = k;
                high = k - 1;
            }
        }

        return ans;
    }
};
