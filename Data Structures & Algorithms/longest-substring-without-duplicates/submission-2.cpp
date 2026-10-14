class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> flag (300, 0);
        int l = 0, n = s.size();
        int best = 0;
        if (n == 0) return 0;
        for (int i = 0; i < n; i++)
        {
            if (flag[s[i]])
            {
                while (s[l] != s[i])
                {
                    flag[s[l]] = 0;
                    l++;
                }
                flag[s[l]] = 0;
                l++;
            }

            flag[s[i]] = 1; 
            best = max(best, i - l + 1);
        }
        return best;
    }
};
