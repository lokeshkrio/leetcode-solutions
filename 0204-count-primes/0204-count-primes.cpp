class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isPrime(n,true);  

        int ans = n >= 2 ? n - 2 : 0;

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    if (isPrime[j]) {
                        isPrime[j] = false;
                        ans--;
                    }
                }
            }
        }
        return ans;
    }
};