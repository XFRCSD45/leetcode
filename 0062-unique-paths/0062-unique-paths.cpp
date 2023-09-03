class Solution {
public:
    int solve(int m, int n, int x, int y, vector<vector<int>>&visited,vector<vector<int>>&dp)
    {
            if(x==n-1 && y==m-1)
            {
                 return 1;
            }
        if(dp[y][x]!=-1)
            return dp[y][x];
        int right=0, down=0;
        visited[y][x]=1;
        if(x+1<n && y<m && visited[y][x+1]==0)
        {
               right=solve(m,n,x+1,y,visited,dp);
        }
        if(x<n && y+1<m && visited[y+1][x]==0)
        {
               down=solve(m,n,x,y+1,visited,dp);
        }
        visited[y][x]=0;
        return dp[y][x]= right+down;
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>visited(m,vector<int>(n,0));
         vector<vector<int>>dp(m,vector<int>(n,-1));
        int x=0,y=0;
        return solve(m,n,x,y,visited,dp);
    }

};