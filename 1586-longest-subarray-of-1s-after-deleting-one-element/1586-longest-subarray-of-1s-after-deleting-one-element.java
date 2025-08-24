class Solution {
    public int longestSubarray(int[] nums) {
        int n = nums.length;
        int arr[]=new int [n];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                sum+=1;
                arr[i]=sum;
            }
            else
            {
                sum=0;
            }
        }
        int maxi=0;
        sum=0;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]==1)
            {
                sum+=1;
                maxi=Math.max(maxi,sum);
                nums[i]=sum;
            }
            else
            {
                sum=0;
            }
        }
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]==0)
            {
                maxi=Math.max(maxi, nums[i+1]+arr[i-1]);
            }
        }
        if(maxi==n)
        {
            maxi--;
        }
        return maxi;
    }
}