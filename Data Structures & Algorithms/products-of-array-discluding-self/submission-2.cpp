class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product = 1, count0 = 0;
        for(int num: nums) {
            if (num)
                product *= num;
            else count0++;
        }

        vector<int> output;
        
        if (count0 == 0) 
            for(int num: nums) 
                output.push_back(product/num);
        else if(count0 == 1)
            for(int num: nums) {
                if (num) output.push_back(0);
                else output.push_back(product);
            }
        else 
            for(int num: nums) output.push_back(0);
        return output;
    }
};
