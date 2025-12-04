class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        int ans=0;
        int i=n-1;
        int curr =0;
        int stationary=0;
        while(i>=0)
        {
            if(s[i]=='L')
            {
                curr++;
            }
            else if(s[i]=='R')
            {
                if(curr!=0)
                {
                    ans+=curr+1;
                    stationary++;
                }
                else if(stationary!=0)
                {
                    ans++;
                }
                curr=0;
            }
            else
            {
                ans+=curr;
                stationary++;
                curr=0;
            }
            i--;
        }
        return ans;
    }
};