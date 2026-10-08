class Solution {
public:

    string encode(vector<string>& strs) {
        string enc;
        for(auto str: strs) {
            for(char c: str) {
                c = (c + 67) % 256;
                enc += c;
            }
            enc += " ";
        }
        return enc;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string temp;
        for(char c: s) {
            if(c != ' ') temp += (c - 67) % 256;
            else {
                res.push_back(temp);
                temp = "";
            }
        }
        if (!temp.empty())
            res.push_back(temp);
        return res;
    }
};
