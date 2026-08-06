class Solution {
private:
    int product(int x, int t) {
        int p = 1;
        while (x) {
            p = (p * (x % 10)) % t;
            if (p == 0)
                break;
            x = (int)x / 10;
        }
        return p % t;
    }

public:
    int smallestNumber(int n, int t) {
        while (product(n, t)) {
            n++;
        }
        return n;
    }
};