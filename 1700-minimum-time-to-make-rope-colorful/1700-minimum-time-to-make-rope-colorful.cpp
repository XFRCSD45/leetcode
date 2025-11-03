class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int i=0;
        int n = colors.size();
        while(i<n)
        {
            int j=i+1;
            int maxi=neededTime[i];
            int sum=neededTime[i];
            int flag=0;
            while(j<n && colors[j]==colors[i])
            {
                flag=1;
                sum+=neededTime[j];
                maxi=max(maxi,neededTime[j]);
                j++;
            }
            if(flag)
            {
                ans+=sum-maxi;
            }
            i=j;
            
        }
        return ans;
    }
};