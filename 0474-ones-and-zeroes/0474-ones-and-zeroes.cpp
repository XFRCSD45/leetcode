#include <algorithm>
class Solution {
public:
    int findMaxForm(vector<string>& str, int m, int n) {
        int len = str.size();
        vector<vector<vector<int>>>dp(len+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int i=1;i<=len;i++)
        {
            int zeros=count(str[i-1].begin(), str[i-1].end(),'0');
            int ones =count(str[i-1].begin(), str[i-1].end(),'1');
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    int pick=0;
                    if(j-zeros >=0 && k-ones>=0)
                    {
                        pick=dp[i-1][j-zeros][k-ones]+1;
                    }
                    int notPick = dp[i-1][j][k];
                    dp[i][j][k]=max(pick,notPick);
                }
            }
        }
        return dp[len][m][n];
    }
};