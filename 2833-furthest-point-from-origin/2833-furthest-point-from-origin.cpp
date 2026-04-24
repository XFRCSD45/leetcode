class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans=0;
        int dash=0;
        for(char x:moves)
        {
            if(x=='L')
            {
                ans++;
            }
            else if(x=='R')
            {
                ans--;
            }
            else
            {
                dash++;
            }
        }
        ans= abs(ans)+dash;
        return ans;
    }
};