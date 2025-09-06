class Solution {
    public long minOperations(int[][] queries) {
     int n = queries.length;
        long result=0;
        for(int i=0;i<n;i++)
        {
             long  l = queries[i][0];
             long r = queries[i][1];
             long ans=0;
            for(int j=0;j<=15;j++)
            {
                 long start = (long)Math.pow(4,j);
                 long end = start * 4 -1;
                 long numbers = Math.min(r,end) - Math.max(l,start) + 1;
                if(numbers <= 0)
                {
                    continue;
                }
                ans +=(1L*numbers*(j+1));
            }
            result += (ans+1)/2;
        }
        return result;   
    }
}