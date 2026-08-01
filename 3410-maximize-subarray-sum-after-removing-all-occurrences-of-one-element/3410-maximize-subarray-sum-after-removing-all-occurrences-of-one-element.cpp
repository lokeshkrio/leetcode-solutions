class Solution {
public:
    long long maxSubarraySum(vector<int>& nums) {
        using ll = long long;

        ll ans = *max_element(nums.begin(), nums.end());

        ll prefix = 0;
        ll minPrefix = 0;
        ll modifiedMinPrefix = 0;

        unordered_map<int, int> cnt;
        unordered_map<int, ll> best;

        for (int x : nums) {
            prefix += x;

            ans = max(ans, prefix - modifiedMinPrefix);

            if (x < 0) {
                ++cnt[x];

                if (!best.count(x))
                    best[x] = minPrefix + x;
                else
                    best[x] = min(best[x], minPrefix) + x;

                modifiedMinPrefix = min(
                    modifiedMinPrefix,
                    min(1LL * cnt[x] * x, best[x])
                );
            }

            minPrefix = min(minPrefix, prefix);
            modifiedMinPrefix = min(modifiedMinPrefix, minPrefix);
        }

        return ans;
    }
};