class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
     int n = mat.length;
     int m = mat[0].length;
     int result[]=new int[n*m];
     int pos=0;
     ArrayList<Integer> temp = new ArrayList<Integer>();
     for(int i=0;i<n+m-1;i++)
     {
        temp.clear();
        int r = i<m ? 0 : i-m+1;
        int c = i<m ? i : m-1;
        while(r < n && c > -1)
        {
            temp.add(mat[r][c]);
            r++;
            c--;
        }
        if(i%2==0)
        {
            Collections.reverse(temp);
        }
        for(int j=0;j<temp.size();j++)
        {
            result[pos++]=temp.get(j);
        }

     }
     return result;
    }
}