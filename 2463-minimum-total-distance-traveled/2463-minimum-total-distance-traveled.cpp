class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        const long long INF = 1e18;
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(101,INF)));
        function<long long(int, int, int)> solve = [&](int i, int j, int count)-> long long{
            if(i>=n)
            {
                return 0;
            }
            if(j>=m)
            {
                return INF;
            }
            if(dp[i][j][count]!=INF)
            {
                return dp[i][j][count];
            }
            long long option1 = solve(i, j+1, 0);
            long long option2 = INF;
            if(count< factory[j][1])
            {
                option2 = abs(robot[i]-factory[j][0]) + min(solve(i+1, j,count+1), solve(i+1, j+1, 0));
            }
            return dp[i][j][count]=min(option1, option2);
        };
        return solve(0,0,0);
    }
};