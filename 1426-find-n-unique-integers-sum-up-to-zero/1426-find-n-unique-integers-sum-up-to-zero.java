class Solution {
    public int[] sumZero(int n) {
        int [] arr = new int[n];
        int pos=0;
        int curr = 1;
        for(int i=0;i<n/2;i++)
        {
            arr[pos++]=curr;
            arr[pos++]=curr*-1;
            curr++;
        }
        if((n & 1) == 1)
        {
            arr[pos]=0;
        }
        return arr;
    }
}