class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int count=0;
        int n = matrix.length;
        int m = matrix[0].length;
        int mini=Integer.MIN_VALUE, posMin=Integer.MAX_VALUE;
        long sum=0, flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]<0)
                {
                    count++;
                    mini=Math.max(mini, matrix[i][j]);
                }else if(matrix[i][j]==0)
                {
                    flag=1;
                }else
                {
                    posMin=Math.min(posMin, matrix[i][j]);
                }
                sum+=Math.abs(matrix[i][j]);
            }
        }
        if(count%2==1 && flag==0)
        {
            mini=Math.abs(mini);
            mini=Math.min(mini,posMin);
            sum-=2*mini;
        }
        return sum;
    }
}