class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        vector<int>prefix(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            prefix[i]+=s[i]=='1'?1:0;
            if(i>0)
            {
                prefix[i]+=prefix[i-1];
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
            {
                ans+=prefix[i];
            }
            while(i>=0&&s[i]=='0')
            {
                i--;
            }
        }
        return ans;
    }
};