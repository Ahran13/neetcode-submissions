class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string> st;
        for(auto token: tokens)
        {
            if (token == "+" || token == "-" || token == "/" || token == "*") {
                int y = stoi(st.back()); st.pop_back();
                int x = stoi(st.back()); st.pop_back();

                int result;
                if (token == "+") result = x + y;
                else if (token == "*") result = x * y;
                else if (token == "-") result = x - y;
                else result = x / y;

                st.push_back(to_string(result));
            }
            else
                st.push_back(token);  
        }
        return stoi(st.back());
    }
};
