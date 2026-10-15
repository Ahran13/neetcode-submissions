class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq (26, 0);
        int n = s.size(), best = 0;
        int maxfreq = 0;
        if (n == 0) return 0;

        int l = 0, r = 0;
        while(l < n && r < n) {
            freq[s[r] - 'A']++;

            if (freq[s[r] - 'A'] > maxfreq) 
                maxfreq = freq[s[r] - 'A'];

            if (r - l + 1 - maxfreq <= k) 
                best = max(best, r - l + 1);
            
            else {
                freq[s[l] - 'A']--;
                l++;
            }
            r++;
        }
        return best;
    }
};
