class Solution {
public:
    int solve(vector<int>& v, int x, int pos) {
        int n = v.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int diff = abs(v[pos] - v[i]) / x;
            ans += diff;
        }
        return ans;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> vec;
        int mod = -1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                vec.push_back(grid[i][j]);
                if (mod != -1 && grid[i][j] % x != mod) {
                    return -1;
                } else {
                    mod = grid[i][j] % x;
                }
            }
        }
        sort(vec.begin(), vec.end());
        return solve(vec, x, (vec.size()) / 2);
    }
};