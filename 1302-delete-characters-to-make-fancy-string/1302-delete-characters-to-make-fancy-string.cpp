class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        if(n<3)
        {
            return s;
        }
        string ans = "";
        ans+=s[0];
        int i=1;
        while(i<n-1)
        {
            if(s[i]==s[i-1] && s[i]==s[i+1])
            {
                i++;
                continue;
            }
            else
            {
                ans+=s[i];
            }
            i++;
        }
        ans+=s[n-1];
        return ans;
    }
};