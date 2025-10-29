class Solution {
public:
    int smallestNumber(int n) {
        int lg = log2(n);
        int ans = pow(2,lg+1)-1;
        return ans;
    }
};