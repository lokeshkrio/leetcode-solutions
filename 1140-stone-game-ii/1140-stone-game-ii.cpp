class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int M = n; M >= 1; --M) {
                int maxTake = min(2 * M, n - i);

                if (maxTake >= n - i) {
                    dp[i][M] = suffix[i];
                    continue;
                }

                int best = 0;

                for (int X = 1; X <= maxTake; ++X) {
                    int nextM = max(M, X);

                    best = max(best, suffix[i] - dp[i + X][nextM]);
                }

                dp[i][M] = best;
            }
        }

        return dp[0][1];
    }
};