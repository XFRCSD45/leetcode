class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s=="")
            return true;
        int n=t.size(), m=s.size();
        int i=0, j=0;
        while(j<n)
        {
                if(t[j]==s[i])
                {
                    i++;
                    if(i==m)
                    {
                          break;
                    }
                }
            j++;
        }
        if(i==m)
            return true;
        else
            return false;
    }
};