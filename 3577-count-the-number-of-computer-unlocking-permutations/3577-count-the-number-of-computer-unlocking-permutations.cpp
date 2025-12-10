class Solution {
public:
    int countPermutations(vector<int>& v) {
        int first = v[0];
        int n = v.size();
        int mod = 1e9 + 7;
        for (int i = 1; i < n; i++) {
            if (v[i] <= first) {
                return 0;
            }
        }
        map<int, int> m;
        for (int i = 1; i < n; i++) {
            m[v[i]]++;
        }
        long long res = 1;
        for (int i = n-1; i>= 2; i--) {
            res = (res * i) % mod;
        }
        return (int)res;
    }
};