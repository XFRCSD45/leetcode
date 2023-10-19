class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m=s.size(), n=t.size();
       int del=0, i=m-1;
        string a="", b="";
        while(i>=0)
        {
             if(s[i]=='#')
             {
                 del++;
                 i--;
             }
            else
            {
                 if(del>0)
                 {
                    del--;
                     i--;
                 }
                else
                {
                      a=a+s[i];
                    i--;
                }
            }
        }
        
        i=n-1;
        del=0;
        while(i>=0)
        {
             if(t[i]=='#')
             {
                 del++;
                 i--;
             }
            else
            {
                 if(del>0)
                 {
                     del--;
                     i--;
                 }
                else
                {
                      b=b+t[i];
                    i--;
                }
            }
        }
        
        if(a==b)
            return true;
        return false;
    }
};