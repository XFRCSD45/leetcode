class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k, int n, vector<int>& prefix) {
        for(int i=k-1;i<n-k;i++)
        {
             if(prefix[i]>=k && prefix[i+k]>=k )
             {
                return true;
             }
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n,1);
        prefix[0]=1;
        for(int i=1;i<n;i++)
        {
             if(nums[i-1]<nums[i])
             {
                prefix[i]=prefix[i-1]+1;
             }
        }
        int low=1;
        int high = n;
        int ans =INT_MIN;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(hasIncreasingSubarrays(nums,mid, n, prefix))
            {
                ans = max(ans,mid);
                low=mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
     return ans;   
    }
};