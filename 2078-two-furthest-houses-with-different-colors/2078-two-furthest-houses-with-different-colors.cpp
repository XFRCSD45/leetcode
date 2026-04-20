class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i=0;
        int ans=0;
        while(i<n)
        {
            int j=n-1;
            int k=0;
            while(k<i && colors[i]==colors[k])
            {
                k++;
            }
            ans=max(ans,i-k);
            while(j>i && colors[i]==colors[j])
            {
                j--;
            }
            ans=max(ans,j-i);
            i++;
            while(i+1<n &&  colors[i]==colors[i+1])
            {
                i++;
            }
        }
        return ans;
    }
};