class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>dp(n,INT_MIN);
        auto solve = [&](this auto&& solve, int i) -> int {
            if(i>=n)
            {
                return 0;
            }
            int& res = dp[i];
            if (res != INT_MIN) return res;
            int sum = 0;
            for (int j = 1; j <= 3 && i + j <= n; j++) {
                sum += stoneValue[i + j - 1];
                res = max(res, sum - solve(i + j));
            }
            return res;
        };
        int temp = solve(0);
        cout<<temp<<endl;
        if(temp>0)
        {
            return "Alice";
        }
        else if(temp<0)
        {
            return "Bob";
        }
        return "Tie";
    }
};