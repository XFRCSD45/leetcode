class Solution {
    public boolean hasAlternatingBits(int n) {
           int curr=n&1;
           n>>=1;
           while(n!=0)
           {
             int temp = n&1;
             if(temp==curr)
             {
                return false;
             }
             curr=temp;
             n>>=1;
           }   
           return true;
    }
}