class Solution {
    public int maxArea(int[] h) {
        int n = h.length;
        int i=0, j=n-1;
        int ans=0;
        while(i<j)
        {
            int curr = (j-i)*Math.min(h[i], h[j]);
            ans=Math.max(ans, curr);
            if(h[i]<=h[j])
            {
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
}