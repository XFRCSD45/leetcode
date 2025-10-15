class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefix(n,0);
        prefix[0]=1;
        for(int i=1;i<n;i++)
        {
             if(nums[i-1]<nums[i])
             {
                prefix[i]=prefix[i-1]+1;
             }
             else
             {
                prefix[i]=1;
             }
        }
        for(int i=k-1;i<n-k;i++)
        {
             if(prefix[i]>=k && prefix[i+k]>=k )
             {
                return true;
             }
        }
        return false;
    }
};