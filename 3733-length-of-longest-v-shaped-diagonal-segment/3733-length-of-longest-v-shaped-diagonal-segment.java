class Solution {
    public static int[][] dir = {
            { 1, 1 },
            { 1, -1 },
            { -1, -1 },
            { -1, 1 }
    };

    public static int helper(int i, int j, int val, int dr, int n, int m, int f, int[][] grid, int[][][][] dp) {
        int newRow = i + dir[dr][0];
        int newCol = j + dir[dr][1];
        if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || grid[newRow][newCol] != val) {
            return 0;
        }
        if (dp[newRow][newCol][dr][f] != 0) {
            return dp[newRow][newCol][dr][f];
        }
        dp[newRow][newCol][dr][f] = 1;
        int op1 = helper(newRow, newCol, val == 2 ? 0 : 2, dr, n, m, f, grid, dp);
        int op2 = 0;
        if (f == 1) {
            op2 = helper(newRow, newCol, val == 2 ? 0 : 2, (dr + 1) % 4, n, m, 0, grid, dp);
        }
        dp[newRow][newCol][dr][f] += Math.max(op1, op2);
        return dp[newRow][newCol][dr][f];
    }

    public int lenOfVDiagonal(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int dp[][][][] = new int[n][m][5][2];
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        result = Math.max(result, 1 + helper(i, j, 2, k, n, m, 1, grid, dp));
                    }
                }
            }
        }
        return result;
    }
}