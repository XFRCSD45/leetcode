class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0], curr=nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            curr = max(nums[i], curr+nums[i]);
            sum=max(sum,curr);
        }
        return sum;
    }
};