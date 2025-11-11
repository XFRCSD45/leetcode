#include <algorithm>
class Solution {
public:
    int findMaxForm(vector<string>& str, int m, int n) {
        int len = str.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=len;i++)
        {
            int zeros=count(str[i-1].begin(), str[i-1].end(),'0');
            int ones =count(str[i-1].begin(), str[i-1].end(),'1');
            for(int j=m;j>=zeros;j--)
            {
                for(int k=n;k>=ones;k--)
                {
                    dp[j][k]=max(dp[j][k], dp[j-zeros][k-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};