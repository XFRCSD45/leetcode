class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;

        for (int day = 1; day <= n; day++) {
            int start = day + delay;
            int end = min(day + forget - 1, n);
            for (int j = start; j <= end; j++) {
                dp[j] = (dp[j] + dp[day]) % MOD;
            }
        }

        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            ans = (ans + dp[i]) % MOD;
        }

        return (int)ans;
    }
};