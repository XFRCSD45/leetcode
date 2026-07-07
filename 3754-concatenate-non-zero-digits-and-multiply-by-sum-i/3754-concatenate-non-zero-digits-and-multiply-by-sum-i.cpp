class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long curr=0;
        long long mul =1;
        while(n)
        {
            int d = n%10;
            n/=10;
            if(d==0)
            {
                continue;
            }
            sum+=d;    
            curr+=d*mul;
            mul*=10;
        }
        return sum*curr;

    }
};