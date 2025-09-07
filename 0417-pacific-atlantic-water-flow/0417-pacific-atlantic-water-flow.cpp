class Solution {
public:
    int rows, cols;
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool isValid(int x, int y) {
        if (x < 0 || x >= rows || y < 0 || y >= cols) {
            return false;
        }
        return true;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        rows = n;
        cols = m;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> pac(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            q.push({i, 0});
            pac[i][0] = 1;
        }
        for (int j = 0; j < m; j++) {
            q.push({0, j});
            pac[0][j] = 1;
        }
        while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        vis[p.first][p.second] = 1;
                        for (auto d : dir) {
                            int x = p.first + d.first;
                            int y = p.second + d.second;
                            if (isValid(x, y) && !vis[x][y] &&
                                heights[x][y] >= heights[p.first][p.second]) {
                                pac[x][y] = 1;
                                q.push({x, y});
                            }
                        }
                    }
        vis.assign(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            q.push({i, m-1});
            atl[i][m-1] = 1;
        }
        for (int j = 0; j < m; j++) {
            q.push({n-1, j});
            atl[n-1][j] = 1;
        }
        while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        vis[p.first][p.second] = 1;
                        for (auto d : dir) {
                            int x = p.first + d.first;
                            int y = p.second + d.second;
                            if (isValid(x, y) && !vis[x][y] &&
                                heights[x][y] >= heights[p.first][p.second]) {
                                atl[x][y] = 1;
                                q.push({x, y});
                            }
                        }
                    }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};