class TimeMap {
    unordered_map<string, vector<pair<int, string>>> t;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        t[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!t.count(key))
            return "";

        auto &vec = t[key];

        int low = 0, high = vec.size() - 1;
        string ans = "";

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if (vec[mid].first <= timestamp) {
                ans = vec[mid].second;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};
