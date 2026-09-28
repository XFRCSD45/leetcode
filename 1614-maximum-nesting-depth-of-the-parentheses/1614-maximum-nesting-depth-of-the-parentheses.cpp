class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int ans=0, curr=0;
        int i=0;
        while(i<n)
        {
            if(s[i]=='(')
            {
                curr++;
                ans=max(ans,curr);
            }
            else if(s[i]==')')
            {
                curr--;
            }
            i++;
        }
        return ans;
    }
};