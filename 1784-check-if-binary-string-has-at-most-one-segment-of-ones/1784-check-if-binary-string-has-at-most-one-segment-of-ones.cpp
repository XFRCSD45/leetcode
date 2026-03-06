class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int i=1;
        while(i<n)
        {
            if(s[i]=='1' && s[i-1]=='0')
            {
                return false;
            }
            i++;
        }
        return true;
    }
};