class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> eve(26, 0), odd(26, 0);
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            int curr = s2[i] - 'a';
            if (i & 1) {
                odd[curr]++;
            } else {
                eve[curr]++;
            }
        }
        for (int i = 0; i < n; i++) {
            int curr = s1[i] - 'a';
            if (i & 1) {
                if (odd[curr] <= 0) {
                    return false;
                }
                odd[curr]--;
            } else {
                if (eve[curr] <= 0) {
                    return false;
                }
                eve[curr]--;
            }
        }
        return true;
    }
};