class Solution {
    public int longestSubarray(int[] nums) {
        int n = nums.length;
        int arr[]=new int [n];
        int sum=0;
        int maxi=0;
        int prev=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                sum+=1;
                arr[i]=sum;
            }
            else
            {
                if(prev!=-1)
                {
                    maxi=Math.max(maxi, prev+sum);
                }
                prev=sum;
                sum=0;
            }
        }
        if(prev==-1)
        {
            prev=0;
        }
        maxi=Math.max(maxi,prev+sum);
        if(maxi==n)
        {
            maxi--;
        }
        return maxi;
    }
}