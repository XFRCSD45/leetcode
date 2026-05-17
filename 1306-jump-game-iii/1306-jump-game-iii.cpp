class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        function<int(int)>solve=[&](int curr)->int
        {
             if(curr < 0 || curr >= n)
                return false;

            if(arr[curr] == 0)
                return true;

            if(dp[curr] == 0)
                return false;

            if(dp[curr] == 1)
                return true;

            if(dp[curr] == 2)
                return false;

            dp[curr] = 0;

            bool left = solve(curr - arr[curr]);
            bool right = solve(curr + arr[curr]);

            bool ans = left || right;

            dp[curr] = ans ? 1 : 2;

            return ans;
        };
        return solve(start);
    }
};