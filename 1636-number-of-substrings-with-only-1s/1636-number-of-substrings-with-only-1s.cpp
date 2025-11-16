class Solution {
public:
    int numSub(string s) {
        int n =s.size();
        long long int ans =0;
        int i=0;
        long long int m = pow(10,9)+7;
        while(i<n)
        {
            if(s[i]=='1')
            {
                int j=i+1;
               long long int count=1;
               ans++;
                while(j<n && s[j]=='1')
                {
                    count++;
                    j++;
                    ans+=count;
                    ans%=m;
                }
                i=j;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};