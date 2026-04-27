class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
     vector<vector<pair<int,int>>>dir= {{{0,1}, {0, -1}}, {{-1,0},{1,0}}, {{0, -1}, {1, 0}}, {{0,1}, {1,0}}, {{-1,0}, {0,-1}}, {{-1,0}, {0,1}}};
     vector<vector<vector<int>>>possible  = {{{1,3,5}, {1,4,6}}, {{2,3,4}, {2,5,6}}, {{1,4,6}, {5,2,6}}, {{5,3,1}, {6,5,2}}, {{2,3,4}, {4,6,1}}, {{4,3,2}, {3,5,1}}};

     queue<pair<int,int>>q;
     q.push({0,0});
     vector<vector<int>>visited(n, vector<int>(m,0));
     while(!q.empty())
     {
        pair<int,int>p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        if(x==n-1 && y==m-1)
        {
            return true;
        }
        visited[x][y]=1;
        int curr = grid[x][y];
        vector<pair<int,int>>directions = dir[curr-1];
        for(int j=0;j<2;j++)
        {
          vector<int>ways=possible[curr-1][j];
          int nx = x+ directions[j].first;
          int ny = y+ directions[j].second;
          if(nx <n && nx>=0 && ny<m && ny>=0 && !visited[nx][ny] && find(ways.begin(), ways.end(), grid[nx][ny])!=ways.end())
          {
            q.push({nx,ny});
          }   
        }
     }
     return false;
    }
};