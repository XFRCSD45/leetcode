class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        function<int(int)>solve = [&](int curr)->int
        {
            if(curr>=n)
            {
                return 0;
            }
            if(curr==n-1)
            {
                return dp[curr]=nums[curr];
            }
            if(dp[curr]!=-1)
            {
                return dp[curr];
            }
            int op1= solve(curr+1);
            int op2 = nums[curr] + solve(curr+2);
            dp[curr] = max(op1,op2);
            return dp[curr];
        };
        return solve(0);
    }
};