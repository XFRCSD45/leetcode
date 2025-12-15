class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        int i=1;
        int n = prices.size();
        int curr =1;
        while(i<n)
        {
            if(prices[i-1]-prices[i]==1)
            {
                curr++;
            }
            else
            {
                curr=1;
            }
            ans+=curr;
            i++;
        }
        ans++;
        return ans;
    }
};