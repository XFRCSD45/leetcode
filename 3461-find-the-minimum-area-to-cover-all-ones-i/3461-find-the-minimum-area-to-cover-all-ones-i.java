class Solution {
    public int minimumArea(int[][] grid) {
        int n = grid.length;
        int m =grid[0].length;
        int firstRow=n, lastRow=-1, firstCol = m, lastCol=-1;
        for(int i=0;i<n;i++)
        {
              for(int j=0;j<m;j++)
              {
                if(grid[i][j]==1)
                {
                    firstRow=Math.min(firstRow, i);
                    lastRow=Math.max(lastRow,i);
                    firstCol = Math.min(firstCol,j);
                    lastCol = Math.max(lastCol,j);
                }
              }
        }
        int ans = (lastRow-firstRow+1)*(lastCol-firstCol+1);
        return ans;
    }
}