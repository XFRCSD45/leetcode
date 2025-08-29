class Solution {
public:
    long long flowerGame(int n, int m) {
        int e1=n/2;
        int o1=(n+1)/2;
        int e2=m/2;
        int o2=(m+1)/2;
        long long ans = 1ll*e1*o2 + 1ll*o1*e2;
        return ans;
    }
};