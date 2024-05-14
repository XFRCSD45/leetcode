class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
         

        int n=grid.size();
        int m=grid[0].size();
        vector<int>colCount(m,0);
        vector<int>rows(n,0);
        vector<int>cols(m,0);
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==0)
            {
               rows[i]++;
            }
        }
         for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                   if((grid[j][i]==1 && rows[j]%2==0)||(grid[j][i]==0 && rows[j]%2!=0) )
            {
                colCount[i]++;
            }
            }
        }
   
        
         for(int i=1;i<m;i++)
        {
           if(colCount[i]<((n+1)/2))
           {
               cols[i]++;
           }
        }
            
        int ans=0;
         for(int i=n-1;i>=0;i--)
        {
             int temp=0;
            for(int j=m-1;j>=0;j--)
            {
                  int p=m-1-j;
                int val=((rows[i]+cols[j])%2!=0)?!grid[i][j]:grid[i][j];
                if(val)
                {
                    temp=temp+pow(2,p);
                }
                
                
            }
          
             ans+=temp;
        }
        return ans;
    }
};