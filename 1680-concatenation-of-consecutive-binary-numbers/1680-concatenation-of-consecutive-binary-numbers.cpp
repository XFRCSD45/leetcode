class Solution {
public:
    int concatenatedBinary(int n) {
        long long int mod=1000000007;
        long long int ans=1;
        for(int i=2;i<=n;i++)
        {
            int currBits=0;
            int num=i;
            while(num)
            {
                currBits++;
                num>>=1;
            }
            ans= (1LL*ans*pow(2,currBits));
            ans%=mod;
            ans+=i;
            ans%=mod;
        }
        return (int)ans;
    }
};