class Solution {
public:
    int mirrorDistance(int num) {
        int res = 0;
        int n = num;
        while (n > 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }
        return abs(num - res);
    }
};