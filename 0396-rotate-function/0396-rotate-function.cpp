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
        int res =ans;
        for(int i=n-1;i>=0;i--)
        {
            int curr = ans + (total-nums[i]);
            curr = curr - (nums[i]*(n-1));
            ans=curr;
            res=max(res,ans);
        }
        return res;
    }
};