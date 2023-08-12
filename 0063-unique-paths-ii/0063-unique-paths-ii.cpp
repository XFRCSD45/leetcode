class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int x, int y,int m, int n, vector<vector<int>>&visited)
    {
          if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==0 && visited[x][y]==0)
          {
             return true;
          }
        return false;
    }
    int solve(vector<vector<int>>& grid,int x, int y, int &paths, vector<vector<int>>&
visited, int m, int n,vector<vector<int>>& dp)
    {
         if(x==m-1 && y==n-1)
         {
              
             return 1;
         }
        if(dp[x][y]!=-1)
        {
           return dp[x][y];
        }
          visited[x][y]=1;
        int right=0,down=0;
        if(isSafe(grid,x,y+1,m,n,visited))
        {
             
              right=solve(grid,x,y+1,paths,visited,m,n,dp);
              
        }
         
        if(isSafe(grid,x+1,y,m,n,visited))
         {
             down= solve(grid,x+1,y,paths,visited,m,n,dp);
            
         }
      visited[x][y]=0;
       return dp[x][y]=right+down;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]==1)
            return 0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int paths=0;
       return solve(grid,0,0,paths,visited,m,n,dp);
        
        
    }
};