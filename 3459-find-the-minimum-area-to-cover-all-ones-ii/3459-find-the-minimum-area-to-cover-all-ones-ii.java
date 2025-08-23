class Solution {
    public static int minimumArea(int fr, int lr, int fc, int lc, int[][] grid) {
        int n = grid.length;
        int m =grid[0].length;
        int firstRow=n, lastRow=-1, firstCol = m, lastCol=-1;
        for(int i=fr;i<lr;i++)
        {
              for(int j=fc;j<lc;j++)
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
        if(lastRow == -1)
        {
            return 0;
        }
        int ans = (lastRow-firstRow+1)*(lastCol-firstCol+1);
        return ans;
    }
    public int minimumSum(int[][] grid) {
        
        int n = grid.length;
        int m = grid[0].length;
        int result = n*m;
        //case 1 => 1 up 2 bottom
        //case 2 => 2 up 1 bottom
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                int top = minimumArea(0,i,0,m,grid);
                int b1 = minimumArea(i,n,0,j, grid);
                int b2 = minimumArea(i,n,j,m, grid);
                result=Math.min(result, top+b1+b2);
                int t1 = minimumArea(0,i,0,j,grid);
                int t2 = minimumArea(0,i,j,m, grid);
                 b1 = minimumArea(i,n,0,m, grid);
                result=Math.min(result, t1+t2+b1);
            }
        }

        //case 3 => three horizontal rectangles

        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int r1 = minimumArea(0,i,0,m,grid);
                int r2 = minimumArea(i,j,0,m, grid);
                int r3 = minimumArea(j,n,0,m, grid);
                result=Math.min(result, r1+r2+r3);
            }
        }
        int rotatedGrid[][] = new int[m][n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                rotatedGrid[j][n-i-1] = grid[i][j];
            }
        }

        //reapply all the cases after rotating the grid clockwise or anticlockwise
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                int top = minimumArea(0,i,0,n,rotatedGrid);
                int b1 = minimumArea(i,m,0,j, rotatedGrid);
                int b2 = minimumArea(i,m,j,n, rotatedGrid);
                result=Math.min(result, top+b1+b2);
                int t1 = minimumArea(0,i,0,j,rotatedGrid);
                int t2 = minimumArea(0,i,j,n, rotatedGrid);
                 b1 = minimumArea(i,m,0,n, rotatedGrid);
                result=Math.min(result, t1+t2+b1);
            }
        }

        //case 3 => three horizontal rectangles

        for(int i=1;i<m;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                int r1 = minimumArea(0,i,0,n,rotatedGrid);
                int r2 = minimumArea(i,j,0,n, rotatedGrid);
                int r3 = minimumArea(j,m,0,n, rotatedGrid);
                result=Math.min(result, r1+r2+r3);
            }
        } 
        return result;
    }
}