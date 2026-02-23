class Solution {
    Queue<int[]> q=new LinkedList<>();
    boolean[][] visited;
    public int shortestBridge(int[][] grid) {
        int n=grid.length;
        visited=new boolean[n][n];
        boolean found=false;
        int steps=0;

        for(int i=0;i<n && !found;i++){
            for(int j=0;j<n && !found;j++){
                if(grid[i][j]==1)
                {
                    DFS(i,j,grid,n);
                    found=true;
                }
            }
        }

        while(!q.isEmpty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int[] current=q.poll();
                int[][] directions={{-1,0},{1,0},{0,-1},{0,1}};
                for(int[] dir:directions){
                    int nr=current[0]+dir[0];
                    int nc=current[1]+dir[1];

                    if(nr>=0 && nr<n && nc>=0 && nc < n && !visited[nr][nc]){
                        if(grid[nr][nc]==1){
                            return steps;
                        }
                        else{
                            visited[nr][nc]=true;
                            q.offer(new int[]{nr,nc});
                        }

                    }
                }
            }
            steps++;
        }
        return -1;
    }
    public void DFS(int i, int j, int[][] grid, int n){
        if(i<0 || i>=n || j<0 || j>=n || visited[i][j] || grid[i][j] != 1){
            return;
        }
        q.offer(new int[]{i,j});
        visited[i][j]=true;
        int[][] directions={{-1,0},{1,0},{0,-1},{0,1}};
        for(int[] dir:directions){
            DFS(i+dir[0],j+dir[1],grid,n);
        }
    }
}