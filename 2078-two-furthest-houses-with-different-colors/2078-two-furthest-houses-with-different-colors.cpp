class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int first = colors[0];
        int last = colors[n-1];
        if(first!=last)
        {
            return n-1;
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            if(colors[i]!=first)
            {
                ans=max(ans,i);
            }
            if(colors[i]!=last)
            {
                ans=max(ans,n-1-i);
            }
        }
        return ans;
    }
};