class Solution {
    public int[][] sortMatrix(int[][] grid) {
        int n = grid.length;
        ArrayList<Integer> arr = new ArrayList<Integer>();
        int [][] ans = new int[n][n];
        for(int i=0;i<n;i++)
        {
            int curr=i;
            for(int j=0;j<n-i;j++)
            {
                arr.add(grid[curr++][j]);
            }
            Collections.sort(arr, Collections.reverseOrder());
            curr=i;
            int pos=0;
            for(int j=0;j<n-i;j++)
            {
                ans[curr++][j]=arr.get(pos);
                pos++;
            }
            arr.clear();
        }
        for(int j=1;j<n;j++)
        {
            int curr=j;
            for(int i=0;i<n-j;i++)
            {
                arr.add(grid[i][curr++]);
            }
            Collections.sort(arr);
            curr=j;
            int pos=0;
            for(int i=0;i<n-j;i++)
            {
                ans[i][curr++]=arr.get(pos);
                pos++;
            }
            arr.clear();
        }
        return ans;
    }
}