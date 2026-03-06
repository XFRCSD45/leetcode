class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int i=1;
        while(i<n && s[i]=='1')
        {
            i++;
        }
        while(i<n)
        {
            if(s[i]=='1')
            {
                return false;
            }
            i++;
        }
        return true;
    }
};