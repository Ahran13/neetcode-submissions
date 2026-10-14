class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> flag (300, 0);
        int l = 0, n = s.size();
        int bestL = 0, bestR = 0;
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

            if (i - l + 1 > bestR - bestL + 1) 
            {
                bestL = l;
                bestR = i;
            }
        }
        return bestR - bestL + 1;
    }
};
