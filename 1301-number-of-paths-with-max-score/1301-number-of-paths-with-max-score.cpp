class Solution {
private:
    const int mod= 1e9 +7;
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<pair<long long, long long>>>dp(n+1,vector<pair<long long,long long>>(m+1,{-1,-1}));
        dp[n-1][m-1]={0,1};
        board[0][0]='0';
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i+1<n && board[i+1][j]!='X'){
                    if(dp[i+1][j].first+board[i][j]-'0' >dp[i][j].first){
                        dp[i][j].first=dp[i+1][j].first+board[i][j]-'0';
                        dp[i][j].second=dp[i+1][j].second;
                    }
                    else if(dp[i+1][j].first+board[i][j]-'0'  == dp[i][j].first){
                        dp[i][j].second+=dp[i+1][j].second;
                        dp[i][j].second%=mod;
                    }
                }

                if(j+1<m && board[i][j+1]!='X'){
                    if(dp[i][j+1].first+board[i][j]-'0' >dp[i][j].first){
                        dp[i][j].first=dp[i][j+1].first+board[i][j]-'0';
                        dp[i][j].second=dp[i][j+1].second;
                    }
                    else if(dp[i][j+1].first+board[i][j]-'0' == dp[i][j].first){
                        dp[i][j].second+=dp[i][j+1].second;
                        dp[i][j].second%=mod;
                    }
                }

                if(j+1<m && i+1<n && board[i+1][j+1]!='X'){
                    if(dp[i+1][j+1].first+board[i][j]-'0' >dp[i][j].first){
                        dp[i][j].first=dp[i+1][j+1].first+board[i][j]-'0';
                        dp[i][j].second=dp[i+1][j+1].second;
                    }
                    else if(dp[i+1][j+1].first+board[i][j]-'0' == dp[i][j].first){
                        dp[i][j].second+=dp[i+1][j+1].second;
                        dp[i][j].second%=mod;
                    }
                }
            }
        }
        if(dp[0][0].second==-1){
            return {0,0};
        }
        return {(int)dp[0][0].first,(int)dp[0][0].second};
    }
};