class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        int n = queries.size();
        long long result=0;
        for(int i=0;i<n;i++)
        {
            long long  l = queries[i][0];
            long long r = queries[i][1];
            long long ans=0;
            for(int j=0;j<=15;j++)
            {
                long long start = pow(4,j);
                long long end = start * 4 -1;
                // cout<<start<<" "<<end<<endl;
                long long numbers = min(r,end) - max(l,start) + 1;
                if(numbers <= 0)
                {
                    continue;
                }
                ans +=(1LL*numbers*(j+1));
            }
            result += (ans+1)/2;
        }
        return result;
    }
};