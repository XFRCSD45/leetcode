class Solution {
    public long flowerGame(int n, int m) {
        int e1=n/2;
        int o1=(n+1)/2;
        int e2=m/2;
        int o2=(m+1)/2;
        long ans = 1L*e1*o2 + 1L*o1*e2;
        return ans;
    }
}