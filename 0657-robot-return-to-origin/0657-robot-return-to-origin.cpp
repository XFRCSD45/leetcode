class Solution {
public:
    bool judgeCircle(string s) {
        int v=0, h=0;
        int n =s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L')
            {
                h--;
            }
            else if(s[i]=='R')
            {
                h++;
            }
            else if(s[i]=='U')
            {
                v--;
            }
            else
            {
                v++;
            }
        }
        return v==0 && h==0;
    }
};