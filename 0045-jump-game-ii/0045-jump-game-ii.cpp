class Solution {
public:
    int solve(vector<int>&nums,int i, int n,vector<int>&dp)
    {
            if(i==n-1||i>=n)
            {
               return 0;
            }
            if(nums[i]==0)
            {
               return 1e9;
            }
        if(dp[i]!=-1)
        {
              return dp[i];
        }
        int mini=INT_MAX;
        for(int j=1;j<=nums[i];j++)
        {
          int ans= 1+solve(nums,i+j,n,dp);
            mini=min(mini,ans);
        }
        return dp[i]= mini;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,nums.size(),dp);   
    }
};