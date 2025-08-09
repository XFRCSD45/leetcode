class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        {
            return false;
        }
        int count=0;
        n=abs(n);
        while(n)
        {
            if(n&1)
            {
                count++;
            }
            n=n>>1;
        }
        return count<=1;
    }
};