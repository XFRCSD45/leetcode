class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        int i=0;
        int n = prices.size();
        while(i<n)
        {
            int j=i+1;
            long long count=0;
            while(j<n &&(prices[j-1]-prices[j] == 1) )
            {
                count++;
                j++;
            }
            ans+=(count*(count+1))/2;
            i=j;
        }
        ans+=n;
        return ans;
    }
};