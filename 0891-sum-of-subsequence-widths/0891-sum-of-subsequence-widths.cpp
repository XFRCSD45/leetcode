class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const int MOD = 1e9 + 7;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<long long> pow2(n);
        pow2[0] = 1;

        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long contribution =
                (pow2[i] - pow2[n - i - 1]) % MOD;

            ans = (ans + nums[i] * contribution) % MOD;
        }

        ans = (ans + MOD) % MOD;

        return (int)ans;
    }
};