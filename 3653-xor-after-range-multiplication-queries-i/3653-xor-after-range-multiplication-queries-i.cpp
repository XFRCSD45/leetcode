class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long int mod = pow(10,9)+7;
        for(auto q:queries)
        {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            int idx = l;
            while(idx< n && idx<=r)
            {
                nums[idx]=(1LL*nums[idx]*v)%mod;
                idx+=k;
            }
        }
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            ans^=nums[i];
        }
        return ans;
    }
};