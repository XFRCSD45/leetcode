class Solution {
public:
    int minOperations(vector<int>& nums) {
     int n = nums.size();
     int ones=0;
     for(int i=0;i<n;i++)
     {
        if(nums[i]==1)
        {
            ones++;
        }
     }   
     if(ones>0)
     {
        return n-ones;
     }
     vector<vector<int>>g(n,vector<int>(n,0));
     int mini=n+1;
     for(int i=0;i<n;i++)
     {
        g[i][i]=nums[i];
        for(int j=i-1;j>=0;j--)
        {
            g[i][j]=__gcd(nums[i], g[i-1][j]);
            if(g[i][j]==1)
            {
                mini=min(mini,i-j+1);
            }
        }
     }
     if(mini==n+1)
     {
        return -1;
     }
     return mini+n-2;

    }
};