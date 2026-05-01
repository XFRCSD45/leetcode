class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        int total = 0;
        for(int i=0;i<n;i++)
        {
            ans+=nums[i]*i;
            total+=nums[i];
        }
        int res=ans;
        for(int i=n-1;i>=0;i--)
        {
            ans = ans + total - nums[i]*n;
            res=max(ans, res);
        }
        return res;
    }
};