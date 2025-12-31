class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()+nums2.size();
        int m = nums1.size();
        int k = nums2.size();
        int mid1=(n+1)/2;
        int mid2=mid1;
        if(n%2==0)
        {
            mid2++;
        }
        int i=0, j=0;
        int count=1;
        int ans=0;
        while(i<m && j<k)
        {
            if(nums1[i]<=nums2[j])
            {
                if(count==mid1 || count==mid2)
                {
                    ans+=nums1[i];
                }
                i++;
            }
            else
            {
                if(count==mid1 || count==mid2)
                {
                    ans+=nums2[j];
                }
                j++;
            }
            count++;
        }
        while(i<m)
        {
            if(count==mid1 || count==mid2)
                {
                    ans+=nums1[i];
                }
                i++;
                count++;
        }
        while(j<k)
        {
             if(count==mid1 || count==mid2)
                {
                    ans+=nums2[j];
                }
                j++;
                count++;
        }
        if(n&1)
        {
            return ans/1.0;
        }
        return ans/2.0;
    }
};