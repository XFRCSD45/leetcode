class Solution {
public:
    int solve(vector<int>&coins, vector<vector<int>>&dp, int ind, int T)
    {
      if(ind==0)
      {
          return (T%coins[0]==0);
      }
        if(dp[ind][T]!=-1)
        {
            return dp[ind][T];
        }
        int notTake=solve(coins,dp,ind-1,T);
        int take=0;
        if(coins[ind]<=T)
        {
           take=solve(coins,dp,ind,T-coins[ind]);
        }
        return dp[ind][T]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(coins,dp,n-1,amount);
    }
};