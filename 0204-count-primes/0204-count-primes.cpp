class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;

        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i])
                ans++;
            for (int j = i * 2; j < n; j = j + i) {
                isPrime[j] = false;
            }
        }
        return ans;
    }
};