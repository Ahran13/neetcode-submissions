class Solution {
public:
    bool contains(const unordered_map<char, int> &s, const unordered_map<char, int> &t) {
        for(auto &[key, value]: t) {
            auto it = s.find(key);
            if (it == s.end() || it->second < value)
                    return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (n < m)
            return "";

        unordered_map<char, int> tmap, smap;
        for(char ch: t)
            tmap[ch]++;

        int l = 0, bestL = 0, bestLen = INT_MAX;
        for (int r = 0; r < s.size(); r++) {
            smap[s[r]]++;

            while (contains(smap, tmap)) {
                // Update minimum window
                if (bestLen > r - l + 1) 
                    bestL = l, bestLen = r - l + 1;
       
                smap[s[l]]--;
                l++;
            }
        }
        if (bestLen == INT_MAX)
            return "";
        return s.substr(bestL, bestLen);
    }
};
