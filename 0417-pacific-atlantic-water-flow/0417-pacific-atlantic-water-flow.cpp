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
    pair<int, int> dfs(pair<int, int> p, pair<int, int> pos,
                       vector<vector<int>>& heights, vector<vector<int>>& vis,
                       vector<vector<pair<int, int>>>& ans) {
        int x = pos.first;
        int y = pos.second;
        vis[x][y] = 1;

        if ((x == 0 && y == cols - 1) || (x == rows - 1 && y == 0)) {
            return {1, 1};
        }
        pair<int, int> res = ans[x][y];
        int currHeight = heights[x][y];
        vector<pair<int,int>>equals;
        for (auto i : dir) {
            int newX = x + i.first;
            int newY = y + i.second;

            if (isValid(newX, newY) && !(newX == p.first && newY == p.second) && heights[newX][newY] <= currHeight) {
                //  cout<<x<<" "<<y<<" "<<newX<<" "<<newY<<endl;
                if(heights[newX][newY]==currHeight)
                {
                    equals.push_back({newX,newY});
                }
                pair<int, int> response;
                if(vis[newX][newY])
                {
                    response = ans[newX][newY];
                }
                else
                {
                    response =
                    dfs(pos, {newX, newY}, heights, vis, ans);
                }
                ans[x][y] = {ans[x][y].first || response.first,
                             ans[x][y].second || response.second};
            }
        }
        for(auto i : equals)
        {
            ans[i.first][i.second]= {ans[i.first][i.second].first ||ans[x][y].first, ans[i.first][i.second].second ||ans[x][y].second};
        }
        return ans[x][y];
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> result;
        if(n==1 || m==1)
        {
            for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                    result.push_back({i, j});
            }
        }
            return result;
        }
        rows = n;
        cols = m;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<pair<int, int>>> ans(n, vector<pair<int, int>>(m));
        for (int i = 0; i < n; i++) {
            ans[i][0] = {1, 0};
            ans[i][m - 1] = {0, 1};
        }
        for (int j = 0; j < m; j++) {
            ans[0][j] = {1, 0};
            ans[n - 1][j] = {0, 1};
        }
        ans[0][m - 1] = {1, 1};
        ans[n - 1][0] = {1, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                 if(!vis[i][j])
                {
                    dfs({-1, -1}, {i, j}, heights, vis, ans);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if((i==0 || j==0 || i==n-1||j==m-1 ))
                {
                    dfs({-1, -1}, {i, j}, heights, vis, ans);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j]=0;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {               
                    dfs({-1, -1}, {i, j}, heights, vis, ans);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if((i==0 || j==0 || i==n-1||j==m-1 ))
                {
                    dfs({-1, -1}, {i, j}, heights, vis, ans);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ans[i][j].first == 1 && ans[i][j].second == 1) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};