class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>ans(n-2, vector<int>(n-2,-1));
        
        
        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<n-2;j++)
            {
                int maxi=-1;
                
                for(int k=i;k<i+3;k++)
                {
                    
                    maxi=max(maxi,*max_element(grid[k].begin()+j, grid[k].begin()+j+3));
                }
                ans[i][j]=maxi;
            }
        }
        return ans;
    }
};