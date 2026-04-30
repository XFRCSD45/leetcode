class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        function<int(int, int, int)> solve = [&](int i, int j, int curr) {
            if (i >= n || i < 0 || j >= m || j < 0) {
                return INT_MIN;
            }
            if (curr < 0) {
                return INT_MIN;
            }
            if (i == 0 && j == 0) {
                return grid[i][j];
            }
            if (dp[i][j][curr] != -1) {
                return dp[i][j][curr];
            }
            int cost = (grid[i][j] == 1 || grid[i][j] == 2) ? 1 : 0;
            int best =
                max(solve(i - 1, j, curr - cost), solve(i, j - 1, curr - cost));
            if (best == INT_MIN) {
                return dp[i][j][curr] = INT_MIN;
            }

            return dp[i][j][curr] = grid[i][j] + best;
        };

        int ans = solve(n - 1, m - 1, k);
        return ans == INT_MIN ? -1 : ans;
    }
};