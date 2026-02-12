class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int count = freq[s[j]-'a'];
                int flag = 1;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0 && freq[k] != count) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};