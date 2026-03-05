class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int totalOnes=0;
        int onesAtOdd=0;
        int totalZeroes=0;
        int zeroesAtOdd =0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                totalOnes++;
                onesAtOdd = onesAtOdd + (i&1);
            }
            else
            {
                totalZeroes++;
                zeroesAtOdd += (i&1);
            }
        }
        int op1 = onesAtOdd + (totalZeroes - zeroesAtOdd);
        int op2 = zeroesAtOdd + (totalOnes - onesAtOdd);
        return min(op1,op2);
    }
};