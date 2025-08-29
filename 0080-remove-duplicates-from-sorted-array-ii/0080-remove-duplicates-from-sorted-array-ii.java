class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        int pos=0, curr=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[pos])
            {
                if(curr==1)
                {
                    nums[++pos]=nums[i];
                    curr++;
                }
            }
            else
            {
                nums[++pos]=nums[i];
                curr=1;
            }
        }
        return pos+1;
    }
}