class Solution {
public:
    int largestInteger(int n, int s) {
        if (9 * n < s)
            return -1;
        else if (s == 0)
            return 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int d = min(9, s);
            ans = ans * 10 + d;
            s -= d;
        }
        return ans;
    }
};