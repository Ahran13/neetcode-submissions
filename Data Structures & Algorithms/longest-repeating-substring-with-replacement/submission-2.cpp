class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq (26, 0);
        int n = s.size(), best = 0;
        pair<int, char> maxfreq = {0, 0};
        if (n == 0) return 0;

        int l = 0, r = 0;
        while(l < n && r < n) {
            freq[s[r] - 'A']++;

            if (freq[s[r] - 'A'] > maxfreq.first) {
                maxfreq.first = freq[s[r] - 'A'];
                maxfreq.second = s[r] - 'A';
            }

            if (r - l + 1 - maxfreq.first <= k) 
                best = max(best, r - l + 1);
            
            else {
                freq[s[l] - 'A']--;
                if (maxfreq.second == s[l] - 'A') maxfreq.first--;
                l++;
            }
            r++;
        }
        return best;
    }
};
