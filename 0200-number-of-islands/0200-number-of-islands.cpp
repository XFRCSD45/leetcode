class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        vector<pair<int,int>>dir= {{-1,0}, {1,0}, {0,1}, {0,-1}};
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    ans++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty())
                    {
                        pair<int,int>p=q.front();
                        q.pop();
                        int x = p.first;
                        int y = p.second;
                        vis[x][y]=1;
                        for(auto d: dir)
                        {
                            int newX = x+d.first;
                            int newY = y+d.second;
                            if(newX >=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]=='1' && !vis[newX][newY])
                            {
                                vis[newX][newY]=1;
                                q.push({newX, newY});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};