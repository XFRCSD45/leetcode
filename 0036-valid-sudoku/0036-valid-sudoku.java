class Solution {

      public static boolean checkRow(int row, int col, char dig, char[][]board)
        {
            for(int j=0;j<9;j++)
            {
                if(j!=col && board[row][j]==dig)
                {
                    return false;
                }
            }
            return true;
        }
        public static boolean checkCol(int row, int col, char dig, char[][]board)
        {
            for(int i=0;i<9;i++)
            {
                if(i!=row && board[i][col]==dig)
                {
                    return false;
                }
            }
            return true;
        }
        public static boolean checkSubBox(int row, int col, char dig, char[][]board)
        {
            int rowStart = (row/3)*3;
            int colStart = (col/3)*3;
            for(int i=rowStart;i<rowStart+3;i++)
            {
                for(int j=colStart;j<colStart+3;j++)
                {
                    if(i!=row && j!=col && board[i][j]==dig)
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    public boolean isValidSudoku(char[][] board) {
        int n=9, m=9;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]!='.')
                {
                    boolean row = checkRow(i,j, board[i][j], board);
                    boolean col = checkCol(i,j, board[i][j], board);
                    boolean subBox = checkSubBox(i,j, board[i][j], board);

                    if(!row || !col || !subBox)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}