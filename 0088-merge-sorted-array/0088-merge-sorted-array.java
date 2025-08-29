class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i=m-1, j=n-1, pos=m+n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]<=nums2[j])
            {
                nums1[pos--]=nums2[j];
                j--;
            }
            else
            {
                nums1[pos--]=nums1[i];
                i--;
            }
        }
        while(i>=0)
        {
            nums1[pos--]=nums1[i];
            i--;
        }
        while(j>=0)
        {
            nums1[pos--]=nums2[j];
            j--;
        }
    }
}