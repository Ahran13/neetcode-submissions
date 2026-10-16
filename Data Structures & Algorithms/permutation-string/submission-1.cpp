class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        vector<int> freq1 (26, 0), freq2 (26, 0);
        for(char ch: s1) 
            freq1[ch - 'a']++;
        int l = 0, r = s1.size() - 1;
        for(int i = l; i <= r; i++)
            freq2[s2[i] - 'a']++;

        while(r < s2.size()) {
            if (freq1 == freq2)
                return true;

            freq2[s2[l++] - 'a']--;

            if (r < s2.size() - 1) 
                freq2[s2[++r] - 'a']++;
            else 
                break;
        }
        return false;
    }
};
