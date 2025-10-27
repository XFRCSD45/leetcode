class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<pair<int, int>> cams(n);
        int m = bank[0].size();
        int prev = 0;
        for (int i = n - 1; i >= 0; i--) {
            int curr = 0;
            for (int j = 0; j < m; j++) {
                if (bank[i][j] == '1') {
                    curr++;
                }
            }
            if (curr == 0) {
                cams[i] = {0, prev};
            } else {
                cams[i] = {curr, prev};
                prev = curr;
            }
        }
        int ans=0;
        for(int i=n-2;i>=0;i--)
        {
            ans+=cams[i].first*cams[i].second;
        }
        return ans;
    }
};