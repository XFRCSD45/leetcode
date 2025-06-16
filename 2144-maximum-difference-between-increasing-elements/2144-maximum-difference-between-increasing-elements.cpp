class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>maxi(n), mini(n);
        maxi[n-1]=nums[n-1];
        mini[0]=nums[0];
        for(int i=n-2;i>=0;i--)
        {
            maxi[i]=max(maxi[i+1],nums[i]);
        }
        for(int i=1;i<n;i++)
        {
            mini[i]=min(mini[i-1],nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
          ans=max(ans,maxi[i]-mini[i]);
        }
        if(ans==0)
        {
            return -1;
        }
        return ans;

    }
};