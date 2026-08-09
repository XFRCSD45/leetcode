class Solution {
public:
    int stoneGameII(vector<int>& stoneValue) {
         int n = stoneValue.size();
        vector<vector<vector<int>>>dp(2, vector<vector<int>>(n,vector<int>(n+1,-1)));
        auto solve = [&](this auto&& solve,int turn, int i, int M) -> int {
            if(i>=n)
            {
                return 0;
            }
            if (dp[turn][i][M] != -1) return dp[turn][i][M];
            int sum = 0;
            if (turn == 0) {
                int ans = 0;

                for (int k = 1; k <= min(2 * M, n - i); k++) {
                    sum += stoneValue[i + k - 1];
                    ans = max(ans, sum + solve(1,i + k, max(M,k)));
                }

                return dp[turn][i][M] = ans;
            }
            else {

                int ans = INT_MAX;

                for (int k = 1; k <= min(2 * M, n - i); k++) {
                    ans = min(ans, solve(0,i + k, max(M,k)));
                }

                return dp[turn][i][M] = ans;
            }
        };
        int temp = solve(0,0,1);
        return temp;
    }
};