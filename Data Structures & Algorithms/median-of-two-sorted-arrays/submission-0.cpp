class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size())
            return findMedianSortedArrays(b, a);

        int m = a.size(), n = b.size();
        int low = 0, high = m, half = (m + n + 1) / 2;

        while(low <= high)
        {
            int i = low + (high - low) / 2;
            int j = half - i;

            int L1 = (i == 0) ? INT_MIN : a[i - 1];
            int R1 = (i == m) ? INT_MAX : a[i];

            int L2 = (j == 0) ? INT_MIN : b[j - 1];
            int R2 = (j == n) ? INT_MAX : b[j];

            if (L1 <= R2 && L2 <= R1) {
                if ((m + n) % 2 == 1)
                    return max(L1, L2);
                return (double(max(L1, L2)) + min(R1, R2)) / 2.0;
            }
            (L1 > R2) ? high = i - 1 : low = i + 1;
        }
    }
};
