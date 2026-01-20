class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=2)
            {
                int curr=nums[i];
                int mask = 1;
                curr=curr>>1;
                while(curr&1)
                {
                    mask<<=1;
                    curr>>=1;
                }
                mask=~mask;
                ans[i]=mask&nums[i];
            }
            else
            {
                ans[i]=-1;
            }
        }
        return ans;
    }
};