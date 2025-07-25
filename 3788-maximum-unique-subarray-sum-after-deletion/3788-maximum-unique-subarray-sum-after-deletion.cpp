class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(101,-1);
        int ans=0;
        int maxi=-101;
        for(int i=0;i<n;i++)
        {
             maxi=max(maxi,nums[i]);   
            if(nums[i]>0 && v[nums[i]]==-1)
            {
                ans+=nums[i];
                v[nums[i]]=1;
            }
        }
        if(ans==0)
        {
            ans=maxi;
        }
        return ans;
    }
};