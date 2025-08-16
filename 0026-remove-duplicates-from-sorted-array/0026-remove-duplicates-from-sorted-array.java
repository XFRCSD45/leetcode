class Solution {
    public int removeDuplicates(int[] nums) {
        int i=0, j=1, pos=0;
        while(j<nums.length)
        {
           if(nums[i]!=nums[j])
           {
            nums[pos++]=nums[i];
            i=j;
           }    
           j++;
        }
        nums[pos++]=nums[i];
        return pos;
    }
}