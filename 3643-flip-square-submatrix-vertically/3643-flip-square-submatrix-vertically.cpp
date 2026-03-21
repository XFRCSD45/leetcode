class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int i = x, j=min(x+k-1, n-1);
        while(i<j)
        {
            for(int l = y; l<=min(y+k-1, m-1);l++)
            {
                swap(grid[i][l], grid[j][l]);
            }
            i++;
            j--;
        }
        return grid;
    }
};